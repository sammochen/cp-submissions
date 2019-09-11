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
		ll n, x, total = 0;
		cin >> n;
		VLL A(n); // effect if flipped
		REP(i,0,n) {
			cin >> x;
			total += x;
			A[i] = x == 1 ? -1 : 1;
		}
	
		VLL dp(n + 1); // prefix sum of gain if all from i to 0 is flipped
		dp[0] = 0;
		
		ll best = -1;
		
		REP(i,1,n+1) {
			dp[i] = max(dp[i-1] + A[i-1], A[i-1]);
			best = max(best, dp[i]);
		}
		
		cout << total + best << endl;
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
