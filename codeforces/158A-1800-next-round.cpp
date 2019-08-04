/*
Original problem: https://codeforces.com/problemset/problem/158/A
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
		int n, k;
		cin >> n >> k;
		VI A(n);

		REP(i, 0, n) {
			cin >> A[i];
		}

		if (A[0] == 0) {
			cout << 0 << endl;
			return;
		}

		// find the kth participant. if it is 0, keep going left. if it is not, keep going right
		if (A[k - 1] == 0) {
			int index = k - 1;
			while (A[index] == 0) {
				index--;
			}
			cout << index + 1 << endl;
			return;
		}
		else {
			int index = k - 1;
			while (index != n && A[index] == A[k - 1]) {
				index++;
			}
			cout << index << endl;
			return;
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