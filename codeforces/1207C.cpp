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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	void main() {
		ll inf = 1e18 + 5;
		
		ll n, a, b;
		string s;
		
		cin >> n >> a >> b;
		cin >> s;
		
		vector<VLL> dp(n + 1, VLL(2));
		
		dp[0][0] = b;
		dp[0][1] = inf;
		
		REP(i,1,n) {
			if (s[i] == '0' && s[i-1] == '0') {
				dp[i][0] = min(dp[i-1][0], dp[i-1][1] + a) + a + b;
			} else {
				dp[i][0] = inf;
			}
			
			dp[i][1] = min(dp[i-1][0] + a, dp[i-1][1]) + a + 2 * b;
		}
		
		dp[n][0] = min(dp[n-1][0], dp[n-1][1] + a) + a + b;
		
		cout << dp[n][0] << endl;
		
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
