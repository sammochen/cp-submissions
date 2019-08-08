/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_f
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
        string a, b;
        cin >> a >> b;
        // dp[i][j] is the maximum length substring considering the first i/j letters
        vector < VI > dp(a.length() + 1, VI(b.length() + 1));
        REP(i, 1, a.size() + 1) {
            REP(j, 1, b.size() + 1) {
                // if same: dp[i][j] = d[i-1][j-1] + 1
                // else: = max(dp[i-1][j], dp[i][j-1])
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // to find the word, do a 2-pointer approach and print backwards
        stack < char > ans;
        int ptra = a.size(), ptrb = b.size();
        while (dp[ptra][ptrb] != 0) {
            // case 1: move left
            if (dp[ptra][ptrb] == dp[ptra - 1][ptrb]) {
                ptra--;
            } else if (dp[ptra][ptrb] == dp[ptra][ptrb - 1]) {
                ptrb--;
            } else {
                ans.push(a[ptra - 1]);
                ptra--, ptrb--;
            }
        }

        while (ans.size()) {
            cout << ans.top();
            ans.pop();
        }


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