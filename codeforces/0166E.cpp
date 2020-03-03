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
typedef vector<VLL> VVLL;

namespace SOLVE {
	ll mod = 1e9 + 7;
	
	VVLL operator*(VVLL a, VVLL b) {
		VVLL c(a.size(), VLL(b[0].size()));
		
		REP(i,0,a.size()) {
			REP(j,0,a[0].size()) {
				REP(k,0,b[0].size()) {
					c[i][k] += a[i][j] * b[j][k];
					c[i][k] %= mod;
				}
			}
		}
		
		return c;			
	}
	
	VVLL operator^(VVLL a, ll k) {
		if (k == 1) {
			return a;
		}
		VVLL half = a ^ (k / 2);
		half = half * half;
		if (k % 2) {
			half = half * a;
		}
		return half;
	}

	void main() {
		ll n;
		cin >> n;
		
		VVLL a {
			{0,1,1,1},
			{1,0,1,1},
			{1,1,0,1},
			{1,1,1,0}
		};
		
		VVLL ans = a ^ n;
		cout << ans[0][0] << endl;
		
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
