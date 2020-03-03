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
		ll n;
		cin >> n;
		VLL A(n);
		
		ll t = 0;
		REP(i,0,n) {
			cin >> A[i];
			t += A[i];
		}
		
		if (t % 3) {
			cout << 0 << endl;
			return;
		}
		
		ll sum = 0, ans = 0, dp = 0; // dp is how many current t/3 there are
		REP(i,0,n - 1) {
			sum += A[i];
			if (sum == t / 3 * 2) {
				ans += dp;
			}
			dp += (sum == t/3);
			
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
