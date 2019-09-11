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
		ll n, k, a, b;
		cin >> n >> k;
		
		VLL ans(n);
		ll diff = 0;
		
		cin >> ans[0];
		
		REP(i,1,n) {
			cin >> ans[i];
			diff += max(0LL, k - ans[i-1] - ans[i]);
			ans[i] = max(ans[i], k - ans[i-1]);
		}
		
		cout << diff << endl;
		for (ll x : ans) {
			cout << x << ' ';
		}
		cout << endl;
			
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
