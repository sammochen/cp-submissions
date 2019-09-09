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
		VLL a(n + 1); // prefix of a
		
		REP(i,0,n) {
			a[i+1] = a[i] + (s[i] == 'a');
		}
		
		ll ans = 0; 
		REP(i, 0, n + 1) {
			REP(j, i, n + 1) {
				
				ll a1 = a[i];
				ll b = j - i - a[j] + a[i];
				ll a2 = a[n] - a[j];	
				
				ans = max(ans, a1 + b + a2);
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
