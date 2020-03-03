/*
Original problem: https://codeforces.com/problemset/problem/1038/D
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

const ll inf = 1e18 + 5;

namespace SOLVE {
    void main() {
        ll n, opt = 0, allpos = 1, allneg = 1, minx = inf, maxx = -inf;
		ll x;
		cin >> n;

		if (n == 1) {
			cin >> x;
			cout << x << endl;
			return;
		}

		REP(i,0,n) {
			cin >> x;
			opt += abs(x);
			minx = min(minx, x);
			maxx = max(maxx, x);
			if (x <= 0) {
				allpos = 0;
			}
			if (x >= 0) {
				allneg = 0;
			}
		}

		if (allpos) {
			cout << opt - minx * 2 << endl;
		} else if (allneg) {
			cout << opt + maxx * 2 << endl;
		} else {
			cout << opt << endl;
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