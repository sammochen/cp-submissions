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
	ll t(ll x) {
		return (x * (x+1)) / 2;
	}
	
	void main() {
		ll n, v;
		cin >> n >> v;
		// fill up as much 1 as you can, then fill up the rest until its enough
		
		ll ans = (v >= n - 1) ? n - 1 : v + t(n - v) - 1;
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
