/*
Original problem: 
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
    void addmod(ll & x, ll y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    }

    void submod(ll & x, ll y) {
        x -= y;
        if (x < 0) {
            x += mod;
        }
    }

    void main() {
        int n, k;
        cin >> n >> k;
        VI A(n);
        REP(i, 0, n) {
            cin >> A[i];
        }

        VLL dp(k + 2); // number of ways to have dp[i] candies
        dp[k] = 1;

        REP(kid, 0, n) {
            // prefix sum to support O(n * k) complexity
            VLL pref(k + 2);
            REP(candy, 0, k + 1) {
                int lb = max(0LL, candy - A[kid]);
                int ub = candy;
                addmod(pref[lb], dp[candy]);
                submod(pref[ub + 1], dp[candy]);
            }
            REP(i, 1, k + 2) {
                addmod(pref[i], pref[i - 1]);
            }
            dp = pref;
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