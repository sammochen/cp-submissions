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
		ll n, l, r;
		ll mod = 1e9 + 7;
		cin >> n >> l >> r;
		
		VLL f(3);
		while (r % 3 != l % 3) {
			f[r % 3]++;
			r--;
		}
		
		f[r%3]++;
		REP(i,0,3) {
			f[i] += (r - l) / 3;
		}
		
		VLL dp = f;
		REP(i,0,n-1) {
			VLL next(3);
			REP(j,0,3) {
				REP(k,0,3) {
					next[j] += dp[k] * f[(j - k + 3) % 3];
					next[j] %= mod;
				}
			}
			
			dp = next;
		}
		
		cout << dp[0] << endl;		
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
