/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_i
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
    void main() {
        int n;
        cin >> n;
        vector < double > p(n); // prob of heads
        REP(i, 0, n) {
            cin >> p[i];
        }

        vector < vector < double >> dp(n + 1, vector < double > (n + 1)); // dp[i][j] is chance of i heads in j flips
        dp[0][0] = 1; // chance of 0 coins and 0 heads is 1
        
        // works out the probability of all dp[i][j]
        REP(coin, 1, n + 1) {
            REP(heads, 0, coin + 1) {
                if (heads == 0) {
                    dp[coin][heads] = dp[coin - 1][heads] * (1 - p[coin - 1]);
                } else {
                    dp[coin][heads] = dp[coin - 1][heads - 1] * p[coin - 1] + dp[coin - 1][heads] * (1 - p[coin - 1]);
                }
            }
        }

        // add all cases when heads are more than tails
        double ans = 0;
        REP(heads, n / 2 + 1, n + 1) {
            ans += dp[n][heads];
        }
        cout << setprecision(15) << ans << endl;

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