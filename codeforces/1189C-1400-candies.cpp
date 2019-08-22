/*
Original problem: https://codeforces.com/problemset/problem/1189/C
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

namespace SOLVE {
    void main() {
		// prefix sums
        int n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) {
			cin >> A[i];
		}

		VLL p(n+1);
		REP(i,0,n) {
			p[i + 1] = p[i] + A[i];
		}

		int q,a,b;
		cin >> q;
		REP(i,0,q) {
			cin >> a >> b;
			ll ans = p[b] - p[a-1];
			cout << ans / 10 << endl;
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