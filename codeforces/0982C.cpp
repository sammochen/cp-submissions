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
	vector<VLL> E;
	
	ll ans = 0;
	
	ll dfs(ll a, ll prev) {
		ll count = 1;
		for (ll b : E[a]) {
			if (b != prev) {
				ll vv = dfs(b, a);
				if (vv % 2 == 0) {
					ans++;
				} 
				count += vv;
			}
		}
		return count;
	}
	
	void main() {
		ll n;
		cin >> n;
		E.resize(n + 1);
		
		ll a, b;
		REP(i,0,n-1) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		
		if (n % 2 == 1) {
			cout << -1 << endl;
			return;
		}
		
		dfs(1,-1);
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
