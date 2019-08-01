/*
Original problem: https://www.hackerrank.com/challenges/quicksort1
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
		int n;
		cin >> n;
		VI A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		VI L, M, R;
		// add each element to its respective sides
		REP(i, 0, n) {
			if (A[i] == A[0]) {
				M.push_back(A[i]);
			}
			if (A[i] < A[0]) {
				L.push_back(A[i]);
			}
			if (A[i] > A[0]) {
				R.push_back(A[i]);
			}
		}

		// then print in that order
		for (int x : L) {
			cout << x << ' ';
		}
		for (int x : M) {
			cout << x << ' ';
		}
		for (int x : R) {
			cout << x << ' ';
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