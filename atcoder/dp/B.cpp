/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_b
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

const int inf = 1e9+7;
namespace SOLVE {
	void main() {
        // dp[i] is min(dp[i-x] + c) for x in (1, k)
        int n, k;
        cin >> n >> k;
        VI A(n);
        VI dp(n); // dp[i] is the cost to land on i

        REP(i, 0, n) {
            cin >> A[i];
        }

        dp[0] = 0;

        REP(i, 1, n) {
            int best = inf;
            REP(x, 1, k+1) {
                if (i - x >= 0) {
                    best = min(best, dp[i-x] + abs(A[i] - A[i-x]));
                }
            }
            dp[i] = best;
        }

        cout << dp[n - 1] << endl;

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