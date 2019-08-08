/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_h
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

const int mod = 1e9+7;

namespace SOLVE {
    int H, W;

    int valid(int i, int j) {
        return (0 <= i && i < H && 0 <= j && j < W);
    }

	void main() {
		// 2D dp
        cin >> H >> W;

        vector<string> grid(H);
        REP(i,0,H) {
            cin >> grid[i];
        }
        vector<VLL> dp(H, VLL(W));
        dp[0][0] = 1;
        REP(i,0,H) {
            REP(j,0,W) {
                dp[i][j] += (valid(i-1,j) && grid[i-1][j] == '.') ? dp[i-1][j] : 0;
                dp[i][j] += (valid(i,j-1) && grid[i][j-1] == '.') ? dp[i][j-1] : 0;
                dp[i][j] %= mod;
                
            }
        }

        cout << dp[H-1][W-1] << endl;

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