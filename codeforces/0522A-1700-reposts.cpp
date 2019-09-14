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
	void L(string &c) {
		REP(i,0,c.length()) {
			if (c[i] <= 'Z') {
				c[i] += ('z' - 'Z');
			}
		}
	}
		
	void main() {
		ll n;
		cin >> n;
		map<string, ll> f;
		f["polycarp"] = 1;
		
		ll ans = 1;
		
		REP(i,0,n) {
			string a, b, c;
			cin >> a >> b >> c;
			L(a);
			L(c);
			f[a] = f[c] + 1;
			ans = max(ans, f[a]);
		}
		
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
