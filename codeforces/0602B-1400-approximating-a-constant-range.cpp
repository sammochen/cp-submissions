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
		VLL dp(2, 1);
		ll ans = 0;
		
		REP(i,1,n) {
			VLL next(3, 1);
			ll d = A[i] - A[i-1];
			
			REP(j,0,2) {
				next[j] += (j + d >= 2 || j + d < 0) ? 0 : dp[j+d];
				ans = max(ans, next[j]);
			}
			dp = next;
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
