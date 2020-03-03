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
	ll mod(ll a, ll b) {
		ll c = a % b;
		while (c < 0) {
			c += b;
		}
		return c;
	}
	
	void main() {
		ll n, k;
		cin >> n >> k;
		
		VLL A(n);
		
		REP(i,0,n) {
			cin >> A[i];
		}
		
		sort(A.rbegin(), A.rend());
		
		ll total = 0; // how much in total
		ll ans = 0;
		
		REP(i,0,n - 1) {
			total += A[i];
			
			ll nextcut = total - A[i + 1] * (i + 1); // cut required to shave itself off
			
			//cout << i << ' ' << "nextcut" << nextcut << " total " << total << endl;
			
			if (nextcut >= k) {
						
				// shave the top off
				ll firsttake = k - mod(k - nextcut, i + 1);
				ans++;
				nextcut -= firsttake;
				total -= firsttake;
				
				// shave the block off
				ll secondtake = (k / (i + 1)) * (i + 1);
				ans += (nextcut / secondtake);
				total -= (nextcut / secondtake) * secondtake;
			}			
		}
		
		if (total != (n - 1) * A[n - 1]) { // if there are leftovers
			ans++;
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
