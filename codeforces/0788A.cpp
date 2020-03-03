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
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) {
			cin >> A[i];
		}
				
		vector<VLL> dp(n, VLL(2)); 
		// go back to front because its easier regarding signs
		dp[n-1][0] = 0;
		dp[n-1][1] = 0;
		
		RREP(i,n-2,0) {
			ll x = abs(A[i] - A[i+1]); // new
			ll y = x - dp[i+1][0]; // delete from small
			ll z = x - dp[i+1][1]; // delete from big
			
			ll big = max(x, max(y,z));
			ll small = min(x, min(y,z));
			dp[i][0] = small;
			dp[i][1] = big;
		}
		
		ll ans = 0;
		REP(i,0,n) {
			ans = max(ans, dp[i][1]);
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
