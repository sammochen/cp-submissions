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
		ll k;
		cin >> k;
		string s;
		cin >> s;
		ll n = s.size();
		
		// need some function that returns the index of the ith '1'
		VLL ind(n+2);
		ind[0] = -1;
				
		ll cnt = 0;
		REP(i,0,s.size()) {
			if (s[i] == '1') {
				ind[++cnt] = i;
			}
		}
		
		ind[cnt + 1] = n;
		
		ll ans = 0;
		
		if (k != 0) {
			REP(i,1,cnt+1) {
				// for every cnt
				if (i - k < 0) {
					continue;
				} 
				ll low = ind[i-k+1] - ind[i-k];
				ll high = ind[i+1] - ind[i];
				
				ans += (low * high);
			}
		} else {
			REP(i,1,cnt+2) {
				ans += t(ind[i] - ind[i-1] - 1);
			}
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
