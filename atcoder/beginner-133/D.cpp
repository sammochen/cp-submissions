/*
Original problem: https://atcoder.jp/contests/abc133/tasks/abc133_d
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
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll mod = 1e9+7;

namespace SOLVE {
    void main() {
    	int n;
    	cin >> n;
    	VLL A(2 * n);
    	VLL suf(2 * n); // suf[i] gives the sum of A[i] + A[i+2] ... end
    	ll t = 0;

    	REP(i, 0, n) {
    		cin >> A[i];
    		A[n + i] = A[i];
    		t += A[i];
    	}

    	suf[2 * n - 1] = A[n - 1];
    	suf[2 * n - 2] = A[n - 2];
    	RREP(i, 2 * n - 3, 0) {
    		suf[i] = suf[i + 2] + A[i];
    	}

    	REP(i, 0, n) {
    		ll ans = t - 2 * (suf[i + 1] - suf[i + n]);
    		cout << ans;
    		if (i != n - 1) {
    			cout << " ";
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