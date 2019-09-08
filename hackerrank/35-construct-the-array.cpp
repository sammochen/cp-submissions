/*
Original problem: https://www.hackerrank.com/challenges/construct-the-array
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

const ll mod = 1e9+7;

namespace SOLVE {	
	void main() {
		ll n, k, x; // n length, k numbers, x last
		cin >> n >> k >> x;
		if (k == 2) {
			if (n % 2 == x % 2) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		} else if (x != 1) {
			VLL dp(3); // dp[0] is end at 1, dp[1] is end at x, dp[2] is end at everything else
			dp[0] = 1;
			
			REP(i,0,n-1) {
				VLL next(3);
				next[0] = dp[1] + dp[2] * (k - 2) % mod;
				next[1] = dp[0] + dp[2] * (k - 2) % mod;
				next[2] = dp[0] + dp[1] + dp[2] * (k - 3) % mod;
				
				dp = next;
			}
			
			cout << dp[1] % mod << endl;
		} else {
			VLL dp(2); // dp[0] is end at 1, dp[1] is end at everything else
			dp[0] = 1;
			
			REP(i,0,n-1) {
				VLL next(3);
				next[0] = dp[1] * (k - 1) % mod;
				next[1] = dp[0] + dp[1] * (k - 2) % mod;
				
				dp = next;
			}
		
			cout << dp[0] % mod << endl;
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
