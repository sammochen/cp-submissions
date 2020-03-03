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
		REP(i,0,n) cin >> A[i];
		VLL dp(n); // longest ending at i
		
		ll ans = 1;
		dp[0] = 1;
		REP(i,1,n) {
			dp[i] = A[i] > A[i-1] ? dp[i-1] + 1 : 1;
			ans = max(ans, dp[i]);
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
