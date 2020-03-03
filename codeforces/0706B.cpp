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
		ll n, x;
		cin >> n;
		VLL f(100001);
		
		REP(i,0,n) {
			cin >> x;
			f[x]++;
		}
		
		VLL dp(100001); // amount you can buy with i - prefix sum basically
		REP(i,1,100001) {
			dp[i] = dp[i-1] + f[i];
		}		
		
		ll q;
		cin >> q;
		
		REP(i,0,q) {
			cin >> x;
			if (x > 100000) {
				cout << n << endl;
			} else {
				cout << dp[x] << endl;
			}
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
