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
	
	void addmod(ll & a, ll b) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
	}
	
	VLL f(ll x) {
		VLL ans;
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				ans.push_back(i);
				if (i * i != x) {
					ans.push_back(x / i);
				}
			}
		}
		return ans;
	}
	
	void main() {
		ll n, k;
		cin >> n >> k;
		
		VLL dp(n + 1);
		VVLL factors(n + 1);
		
		REP(i,1,n + 1) {
			dp[i] = 1;
			factors[i] = f(i);
		}
		
		REP(t,0,k-1) {
			VLL next(n + 1);
			REP(i,1,n+1) {			
				for (ll fac : factors[i]) {
					addmod(next[i], dp[fac]);
				}
			}
			
			dp = next;
		}
		
		ll ans = 0;
		REP(i,1,n+1) {
			addmod(ans, dp[i]);
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
