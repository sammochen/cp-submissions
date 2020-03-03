/*
Original problem: https://codeforces.com/contest/1201/problem/C
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define MP make_pair
#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const int inf = 1e9 + 7;

namespace SOLVE {
	ll n, k;
	VLL A;

	ll ks(ll med) {
		if (A[n / 2] == med) { // already median - 0
			return 0;
		}
		if (A[n / 2 + 1] > med) { // cannot reach this median - -1
			return -1;
		}

		// linear scan to see how many 'k' is required to get this median
		ll ans = 0;
		REP(i, 0, n / 2 + 1) {
			ans += max(0LL, med - A[i]);
			if (ans >= inf) {
				return inf;
			}
		}
		return ans;
	}

	void main() {

		cin >> n >> k;
		A.resize(n);

		REP(i, 0, n) {
			cin >> A[i];
		}
		// base case
		if (n == 1) {
			cout << A[0] + k << endl;
			return;
		}

		// otherwise - reverse sort and binary search
		// complexity: O(n * log(1e15)) 
		sort(A.rbegin(), A.rend());

		ll L = 0, R = 1e15;
		while (L < R) {
			ll M = (L + R) / 2;
			if (ks(M) > k) {
				R = M;
			}
			else {
				L = M + 1;
			}
		}

		cout << L - 1 << endl;
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