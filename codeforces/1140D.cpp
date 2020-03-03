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
	ll nax = 501, n;
	
	
	vector<VLL> dp(nax, VLL(nax, -1));
	
	ll get(ll a, ll b) { // start with 1,2
		if (dp[a][b] != -1) {
			return dp[a][b];
		}
		if (a - b == 1 || (a == 1 && b == n)) {
			return 0;
		}
		ll left = a == 1 ? n : a-1;
		ll right = b == n ? 1 : b+1;
		dp[a][b] = min(get(left, b) + (a * b * left), get(a, right) + (a * b * right));
		return dp[a][b];
	}
	
	void main() {
		cin >> n;
		cout << get(1,2) << endl;
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
