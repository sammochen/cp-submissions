/*
Original problem: https://codeforces.com/problemset/problem/1196/C
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

const ll inf = 1e5;

namespace SOLVE {
    void main() {
        int n, x, y, a, b, c, d;
        cin >> n;
        int xlow = -inf, xhi = inf, ylow = -inf, yhi = inf;

        REP(i, 0, n) {
        	cin >> x >> y >> a >> b >> c >> d;
			if (a == 0) {
				xlow = max(xlow, x);
			}
			if (b == 0) {
				yhi = min(yhi, y);
			}
			if (c == 0) {
				xhi = min(xhi, x);
			}
			if (d == 0) {
				ylow = max(ylow, y);
			}
        }

		if (xlow > xhi) {
			cout << 0 << endl;
			return;
		}
		if (ylow > yhi) {
			cout << 0 << endl;
			return;
		}
		cout << 1 << ' ' << xlow << ' ' << ylow << endl;
    }
}


signed main() {
	int t;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}