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
		string real, fake;
		cin >> real >> fake;
		ll pos = 0;
		for (char c : real) {
			pos += (c == '+') ? 1 : -1;
		}
	
		vector<double> dp(21); // 10 shift
		dp[10] = 1;
		
		for (char c : fake) {
			vector<double> next(21);
			
			if (c == '?') {	
				REP(i,1,20) {
					next[i+1] += dp[i] / 2.0;
					next[i-1] += dp[i] / 2.0;
				}
			} else if (c == '+') {
				REP(i,1,20) {
					next[i+1] += dp[i];
				}
			} else {
				REP(i,1,20) {
					next[i-1] += dp[i];
				}
			}
			dp = next;
		}
		
		printf("%.20f\n", dp[10+pos]);
			
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
