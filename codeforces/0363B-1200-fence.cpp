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
		ll n, k;
		cin >> n >> k;
		VLL A(n);
		REP(i,0,n) cin >> A[i];
		
		ll cur = 0;
		REP(i,0,k) {
			cur += A[i];
		}
		
		ll sum = cur, ans = 1;
		REP(i,0,n-k) {
			cur += A[i+k];
			cur -= A[i];
			if (cur < sum) {
				cur = sum;
				ans = i + 2;
			}
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
