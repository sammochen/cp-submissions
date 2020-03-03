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
#define MP make_pair

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	void main() {
		ll n, x;
		cin >> n;
		vector<map<ll,ll>> freq(2); // freq[parity][number]
		
		freq[1][0] = 1;
		ll ans = 0;
		ll currentxor = 0;
		
		REP(i,0,n) {
			cin >> x;
			
			currentxor ^= x;
			ans += freq[i%2][currentxor];
			freq[i%2][currentxor]++;
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
