/*
Original problem: https://codeforces.com/problemset/problem/1/A
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
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	ll c(ll a, ll b) {
		return a % b == 0 ? a / b : a / b + 1;
	}
	void main() {
		// in short: ceil(n/a) * ceil(m/a)
		ll n, m, a;
		cin >> n >> m >> a;
		cout << c(n, a) * c(m, a) << endl;
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