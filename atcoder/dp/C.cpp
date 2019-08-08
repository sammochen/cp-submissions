/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_c
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)


#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
    void main() {
        // 2D dp - choose out of the prev day but exclude the same option
        int n;
        cin >> n;

        vector < VLL > happiness(n, VLL(3));
        vector < VLL > dp(n, VLL(3)); // dp[i][j] is the best happiness after i days, last doing j
        REP(i, 0, n) {
            REP(j, 0, 3) {
                cin >> happiness[i][j];
            }
        }

        dp[0] = happiness[0]; // first day is the same! maximum
        REP(i, 1, n) {
            REP(j, 0, 3) {
                ll best = 0;
                REP(k, 0, 3) {
                    if (j != k) {
                        best = max(best, happiness[i][j] + dp[i - 1][k]);
                    }
                }
                dp[i][j] = best;
            }
        }

        ll ans = 0;
        REP(i, 0, 3) {
            ans = max(ans, dp[n - 1][i]);
        }
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