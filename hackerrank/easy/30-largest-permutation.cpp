/*
Original problem: https://www.hackerrank.com/challenges/largest-permutation
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
		int n, k, temp;
		cin >> n >> k;
		VI A(n), index(n); // A[i] is the real array, index[i] gives the location of i
		REP(i, 0, n) {
			// i will change to 0-indexing - it feels easier to manage
			cin >> temp;
			A[i] = temp - 1;
			index[temp - 1] = i;
		}

		// highest numbers have priority
		for (int num = n - 1; num >= 0; num--) {
			// if the number is already in the right place, all good
			if (index[num] == (n - 1 - num)) {
				continue;
			}

			// other variables (prevent using new values of array etc)
			int othernum = A[n - 1 - num];
			int ind = index[num];
			int otherind = n - 1 - num;

			// switch!
			A[ind] = othernum;
			A[otherind] = num;
			index[num] = otherind;
			index[othernum] = ind;

			k--;
			if (k == 0) {
				break;
			}
		}

		for (int x : A) {
			// back to 1-indexed
			cout << x + 1 << " ";
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