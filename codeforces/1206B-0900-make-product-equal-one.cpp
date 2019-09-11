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
		
		ll ans = 0;
		ll sign = 1;
		
		REP(i,0,n) {
			cin >> x;
			sign *= x == 0 ? 0 : abs(x)/x;
			ans += abs(abs(x) - 1);
		}
		
		ans += sign == -1 ? 2 : 0;
		
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
