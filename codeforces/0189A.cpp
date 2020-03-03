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
		VLL x(3);
		cin >> n >> x[0] >> x[1] >> x[2];
		
		VLL dp(n+1, -1); // dp[i] is the most amount of ribbons possible for i
		dp[0] = 0;
		REP(i,1,n+1) {
			ll most = -2;
			REP(j,0,3) {
				if (i >= x[j] && dp[i-x[j]] != -1) most = max(most, dp[i-x[j]]);
			}
			dp[i] = most + 1;
		}
		cout << dp[n] << endl;
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
