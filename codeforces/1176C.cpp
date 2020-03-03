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
		ll n, x;
		cin >> n;
		
		map<ll,ll> M;
		M[4] = 1;
		M[8] = 2;
		M[15] = 3;
		M[16] = 4;
		M[23] = 5;
		M[42] = 6;
		
		VLL dp(7); // dp[i] is the nth legal time this i can happened
		
		dp[0] = 1e9 + 7; 
		
		REP(i,0,n) {
			cin >> x;
			dp[M[x]] = min(dp[M[x] - 1], dp[M[x]] + 1); // bounded by prev number
		}
		
		cout << n - 6 * dp[6] << endl;
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
