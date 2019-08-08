/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_o
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

const ll mod = 1e9+7;

namespace SOLVE {
	void addmod(ll & a, ll b) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
	}
	void main() {
		int n;
		cin >> n;

		vector < VI > x(n, VI(n));
		REP(i, 0, n) {
			REP(j, 0, n) {
				cin >> x[i][j];
			}
		}

		// dp[mask] is how many ways to satisfy up to i with this mask remaining
		VLL dp(1 << n);

		dp[(1 << n) - 1] = 1; // there is 1 way of satisfying 0 people with 111..111 remaining
		REP(i, 0, n) { // for every person
			VLL temp(1 << n);
			REP(mask, 0, (1 << n)) {
				// if (dp[mask]) exists, iterate through and update dp[updatedmask]
				if (dp[mask]) {
					for (int next = 0; next < n; next++) {
						if (x[i][next] && ((1 << next) & mask)) {
							addmod(temp[mask & (~(1 << next))], dp[mask]);
						}
					}
				}
			}
			dp = temp;
		}

		cout << dp[0] << endl;
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