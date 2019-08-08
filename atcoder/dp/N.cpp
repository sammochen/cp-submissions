/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_n
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

const ll inf = 1e18+5;

namespace SOLVE {
    void main() {
        // dp: find the cost of each subarray by choosing the min of possible splits
        int n;
        cin >> n;
        VLL A(n);
        REP(i,0,n){
            cin >> A[i];
        }
        vector<VLL> dp(n, VLL(n)); // dp[i][j] is the min cost to build i-j
        vector<VLL> S(n, VLL(n)); // S[i][j] is the sum of subarray i-j

        REP(length, 0, n) {
            REP(start, 0, n - length) {
                ll end = start + length;
                if (length == 0) {
                    S[start][start] = A[start];
                    dp[start][start] = 0;
                } else {
                    S[start][end] = S[start][end - 1] + A[end];
                    ll best = inf;
                    // dp[start][end] = min(dp[start][mid] + dp[mid + 1][end] + sum[start][end])
                    REP(mid, start, end) {
                        best = min(best, dp[start][mid] + dp[mid + 1][end] + S[start][end]);
                    }
                    dp[start][end] = best;
                }
            }
        }

        cout << dp[0][n-1] << endl;
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