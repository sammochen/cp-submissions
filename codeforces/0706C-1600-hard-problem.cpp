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

const ll inf = 1e18 + 5;

namespace SOLVE {
	void main() {
		ll n;
		cin >> n;
		
		VLL value(n);
		REP(i,0,n) cin >> value[i];
		
		vector<VLL> dp(n + 1, VLL(2, inf)); // 0 is forward, 1 is backward
		
		string f = "", b = ""; // forward, backward
		string sf, sb; // string
		
		dp[0][0] = 0;
		dp[0][1] = 0;
		
		REP(i,1,n+1) {
			cin >> sf;
			
			sb = sf;
			reverse(sb.begin(), sb.end());
			
			if (sf >= f) {
				dp[i][0] = min(dp[i][0], dp[i-1][0]);
			}
			if (sb >= f) {
				dp[i][1] = min(dp[i][1], dp[i-1][0] + value[i-1]);
			}
			if (sf >= b) {
				dp[i][0] = min(dp[i][0], dp[i-1][1]);
			}
			if (sb >= b) {
				dp[i][1] = min(dp[i][1], dp[i-1][1] + value[i-1]);
			}
			
			f = sf, b = sb;
		}
		
		ll ans = min(dp[n][0], dp[n][1]);
		ans = ans >= inf ? -1 : ans;
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
