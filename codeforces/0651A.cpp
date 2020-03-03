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
	vector<VLL> dp(200, VLL(200, -1));
	
	ll get(ll a, ll b) {
		if (a < 0 || b < 0) {
			return -1; // undo one
		}
		if (a == 0 || b == 0) {
			return 0;
		}
		if (dp[a][b] != -1) {
			return dp[a][b];
		}
		dp[a][b] = max(get(a-2,b+1), get(a+1,b-2)) + 1;
		return dp[a][b];
	}
	
	void main() {
		ll a, b;
		cin >> a >> b;
		cout << get(a,b) << endl;
		
		
		
		
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
