/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_a
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
        // dp[i] is min(dp[i-1] + c, dp[i-2] + c)
        int n;
        cin >> n;
        VI A(n);
        VI dp(n); // dp[i] is the cost to land on i

        REP(i, 0, n) {
            cin >> A[i];
        }

        dp[0] = 0;
        dp[1] = abs(A[1] - A[0]);

        REP(i, 2, n) {
            dp[i] = min(dp[i - 1] + abs(A[i - 1] - A[i]), dp[i - 2] + abs(A[i - 2] - A[i]));
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