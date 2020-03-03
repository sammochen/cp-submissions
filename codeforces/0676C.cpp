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
	ll f(string s, ll k) { // tries to delete b's
		s = "b" + s + "b";
		ll n = s.length();
		
		VLL ind(n + 1, -1);
		ll cnt = 0;
		REP(i,0,n) {
			if (s[i] == 'b') {
				ind[++cnt] = i;
			}
		}
		
		if (cnt <= k) {
			return n - 2;
		}
		
		ll ans = 0;
		REP(i,1,cnt-k) {
			ans = max(ans, ind[i+k+1] - ind[i] - 1);
		}
		return ans;
	}
		
	void main() {
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		
		string flip = s;
		REP(i,0,s.size()) {
			flip[i] = s[i] == 'a' ? 'b' : 'a';
		}
		
		ll ans = max(f(s,k), f(flip,k));
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
