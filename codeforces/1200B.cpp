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
		ll n, m, k;
		cin >> n >> m >> k;
				
		VLL A(n);
		REP(i,0,n) cin >> A[i];
		
		
		REP(i,1,n) {
			
			ll target = max(0LL, A[i]-k);
			if (A[i-1] + m < target) { // cant reach y - k
				cout << "NO" << endl;
				return;
			} else { // get him to y - k and retrieve as many blocks
				m += A[i-1] - target;
			}
		}
		
		cout << "YES" << endl;
			
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
