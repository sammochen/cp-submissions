/*
Original problem: https://atcoder.jp/contests/abc136/tasks/abc136_e
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	// helper to see if the array can be 0mod using 'cost' up and 'cost' down
	int good(VLL A, ll mod, ll k) {
		int n = A.size();
		REP(i, 0, n) {
			A[i] = A[i] % mod;
		}

		sort(A.begin(), A.end());

		// work out down/up
		// down[i] is req to down everything up to i-1
		// up[i] is req to up everything after i

		VLL down(n + 1);
		VLL up(n + 1);

		down[0] = 0;
		REP(i, 0, n) {
			down[i + 1] = down[i] + A[i];
		}

		up[n] = 0;
		RREP(i, n - 1, 0) {
			up[i] = up[i + 1] + (mod - A[i]) % mod;
		}

		ll ans = k + 1; // invalid initially
		REP(i, 0, n) {
			// down[i] is down needed up to, not including i
			if (down[i] == up[i]) {
				ans = down[i];
			}
		}
		return ans <= k;
	}

	void main() {
		ll n, k;
		cin >> n >> k;
		VLL A(n);
		ll t = 0;
		REP(i, 0, n) {
			cin >> A[i];
			t += A[i];
		}

		// t is maximum ~1e9
		// i can use O(sqrt(n)) to find all factors
		VLL F;
		for (ll f = 1; f * f <= t; f++) {
			if (t % f == 0) {
				F.push_back(f);
				F.push_back(t / f);
			}
		}

		// largest first: 
		// i will see if it is possible to let this be gcd
		sort(F.rbegin(), F.rend());
		for (ll f: F) {
			if (good(A, f, k)) {
				cout << f << endl;
				return;
			}
		}
		cout << 1 << endl;
		return;
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