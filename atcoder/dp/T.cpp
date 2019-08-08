/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_t
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
	void addmod(ll& a, ll b) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
	}

    void main() {
        int n;
		string s;
		cin >> n >> s;

		// dp[i][j]: number of ways to do the first i with j as the last number
		// 0-indexed 

		vector<VLL> dp(n, VLL(n));
		// base case
		dp[0][0] = 1;

		REP(i, 1, n) {
			// supports O(1) subarray sum
			VLL prefix(n); 
			prefix = dp[i-1];

			REP(j, 1, n) {
				addmod(prefix[j], prefix[j-1]); 
			}

			REP(num, 0, i + 1) { // from 0 up to i, i want to slot a number
				if (s[i - 1] == '<') {
					dp[i][num] = num == 0 ? 0 : prefix[num - 1];
				} else {
					dp[i][num] = num == 0 ? prefix[i] : (prefix[i] - prefix[num - 1] + mod) % mod;
				}
			}
		}

		// the answer is all the possibilities added together
		ll ans = 0;
		REP(i,0,n) {
			addmod(ans, dp[n-1][i]);
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