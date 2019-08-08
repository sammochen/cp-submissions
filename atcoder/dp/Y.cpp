/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_y
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x, l, u) for (ll x = l; x < u; x++)
#define RREP(x, l, u) for (ll x = l; x >= u; x--)

#define PII pair<int, int>
#define PLL pair<ll, ll>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll mod = 1e9 + 7;
namespace SOLVE {
	struct block {
		ll i, j, odd, even;
		block(ll a, ll b) {
			i = a, j = b;
		}
	};

	struct sortblock {
		bool operator()(block a, block b) {
			if (a.i == b.i) {
				return a.j < b.j;
			}
			return a.i < b.i;
		}
	};

	VLL F(200001);
	vector < block > blocks;

	// set up F
	void initF() {
		F[0] = 1;
		REP(i, 1, F.size()) {
			F[i] = F[i - 1] * i % mod;
		}
	}

	// recursive, log(b) time
	ll pow(ll a, ll b) {
		if (b == 0) {
			return 1;
		}
		ll half = pow(a, b / 2);
		ll ans = half * half % mod;
		ans = b % 2 == 1 ? ans * a % mod : ans;
		return ans;
	}

	// a^-1 = a^(p-2) mod p
	ll inverse(ll a) {
		return pow(a, mod - 2);
	}

	// n! / (n - r)! * r!
	ll ncr(ll n, ll r) {
		ll top = F[n];
		ll bot = F[n - r] * F[r] % mod;
		return top * inverse(bot) % mod;
	}

	ll paths(ll a, ll b) {
		return ncr(a + b, a);
	}

	void parity(int ind) {
		blocks[ind].even = 0;
		blocks[ind].odd = 0;
		// for every other block
		REP(i, 0, ind) {
			block b = blocks[i];
			ll di = blocks[ind].i - b.i;
			ll dj = blocks[ind].j - b.j;
			if (di >= 0 && dj >= 0) {
				ll p = paths(di, dj);
				blocks[ind].even += p * b.odd;
				blocks[ind].even %= mod;

				blocks[ind].odd += p * b.even;
				blocks[ind].odd %= mod;
			}
		}
	}

	void main() {
		int H, W, N, a, b;
		cin >> H >> W >> N;
		initF();
		// final answer is combination to the final point: odd parity - even parity
		// i will work out all the odd/even parities of each block using dp

		// i will 'pretend' there is a block at 1,1 and H,W
		blocks.push_back(block(1, 1));
		blocks[0].even = 1;
		blocks[0].odd = 0;

		blocks.push_back(block(H, W));

		REP(i, 0, N) {
			cin >> a >> b;
			blocks.push_back(block(a, b));
		}

		// the blocks are in an order such that if i work with a block, all blocks smaller are considered
		sort(blocks.begin(), blocks.end(), sortblock());

		REP(i, 1, blocks.size()) {
			// work out its odd/even parities
			parity(i);
		}

		ll o = blocks[blocks.size() - 1].odd;
		ll e = blocks[blocks.size() - 1].even;
		ll ans = (o - e + mod) % mod;
		cout << ans << endl;
	}
}

signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}