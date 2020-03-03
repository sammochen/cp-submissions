/*
Original problem: https://codeforces.com/problemset/problem/1197/C
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
		// observed: to minimise the divisions, we need to split where there is the largest differences
		// strategy: find the k - 1 largest differences between adj values,
		//			 ans = biggest - smallest - (k-1) differences

		int n, k;
		cin >> n >> k;
		VI A(n);
		VI diff(n - 1);

		REP(i, 0, n) {
			cin >> A[i];
		}
		REP(i, 0, n - 1) {
			diff[i] = A[i + 1] - A[i];
		}

		// sort from big to small
		sort(diff.rbegin(), diff.rend());

		int ans = A[n - 1] - A[0];
		REP(i, 0, k - 1) {
			ans -= diff[i];
		}

		cout << ans << endl;
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