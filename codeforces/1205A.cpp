/*
Original problem: https://codeforces.com/problemset/problem/1205/A
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
        int n;
		cin >> n;
		if (n % 2 == 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;

			VI A(2 * n);
			int idx = 0;

			REP(i,0, n) {
				A[idx] = 2 * i + 1;
				idx = (idx + n) % (2 * n);
				A[idx] = 2 * i + 2;
				idx = (idx + 1) % (2 * n);
			}

			for (int x : A) {
				cout << x << ' ';
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