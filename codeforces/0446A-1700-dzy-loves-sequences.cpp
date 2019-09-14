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

const ll inf = (ll)1e18 + 5;
namespace SOLVE {
	void main() {
		ll n;
		cin >> n;
		VLL A(n+1, -inf);
		REP(i,1,n+1) cin >> A[i];
		
		vector<VLL> dp(n+1, VLL(2)); // dp[i][used] is the length of the subsegment of strictly increasing
		
		ll ans = 0;
				
		REP(i,1,n+1) {
			dp[i][0] = A[i] > A[i-1] ? dp[i-1][0] + 1 : 1;
			dp[i][1] = A[i] > A[i-1] ? dp[i-1][1] + 1 : 1;
			if (i != 1 && A[i] - A[i-2] >= 2) {
				dp[i][1] = max(dp[i][1], dp[i-2][0] + 2);
			}
			
			ans = max(ans, dp[i][0] + 1); // take the longest streak and +1
			ans = max(ans, dp[i][1]);
		}
		
		cout << min(n, ans) << endl;
		
		 
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
