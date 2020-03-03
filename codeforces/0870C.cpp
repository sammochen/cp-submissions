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

const ll inf = (ll)1e18 + 5;
namespace SOLVE {
	void main() {		
		ll n = 20; // chosen number
		VLL dp(n, -1); 
		VLL A = {4,6,9}; // smallest
		dp[0] = 0;
		
		REP(i,1,n) {
			for (ll a : A) {
				if (i - a >= 0 && dp[i-a] != -1) {
					dp[i] = max(dp[i], dp[i-a] + 1);
				}
			}
		}	
		
		ll q;
		cin >> q;
		REP(i,0,q) {
			ll x, ans;
			cin >> x;
			if (x >= 16) {
				ans = dp[16 + (x % 4)] + (x - 16) / 4;
			} else {
				ans = dp[x];
			}
			ans = ans >= inf ? -1 : ans;
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
