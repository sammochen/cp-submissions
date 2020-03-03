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
		string s;
		cin >> s;
		
		ll n = s.size();
		VLL pre(n);
		REP(i,1,n) {
			pre[i] = pre[i-1] + (s[i] == s[i-1]);
		}
		
		ll q, a, b;
		cin >> q;
		REP(i,0,q) {
			cin >> a >> b;
			
			ll ans = pre[b - 1] - pre[a - 1];
			cout << ans << endl;
		}
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
