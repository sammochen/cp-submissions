/*
Original problem: https://codeforces.com/problemset/problem/1199/A
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
	void main() {
		// brute force - check all (<=7) days before and after - O(n) time
		int n, x, y;
		cin >> n >> x >> y;
		VI A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		// for every number, check the prev x and post y for any that are smaller - if there are none print and return
		for (int i = 0; i < n; i++) {
			int good = 1;
			for (int before = max(0, i - x); before < i; before++) {
				if (A[before] < A[i]) {
					good = 0;
					break;
				}
			}

			for (int after = i + 1; after <= min(i + y, n - 1); after++) {
				if (A[after] < A[i]) {
					good = 0;
					break;
				}
			}

			if (good) {
				cout << i + 1 << endl;
				return;
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