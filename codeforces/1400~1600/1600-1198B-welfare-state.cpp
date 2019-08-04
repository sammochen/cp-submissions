/*
Original problem: https://codeforces.com/problemset/problem/1198/B
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
		// total complexity: O(n + q)
		// use an O(n) array of values and each value comes with a timestamp - 
		// this allows me to know what payouts are relevant to this value
		// updates are O(1) * q
		// find max-suffix in O(q)
		// the final value is max(itself, maxsuffix of the timestamp + 1)
		
		int n, a, b, c;
		cin >> n;
		vector<PII> A(n); // A[i] contains (value, timestamp)
		REP(i, 0, n) {
			cin >> a;
			A[i] = MP(a, -1); // time: -1
		}

		int q;
		cin >> q;
		VI payout(q + 1); // payout[q] = 0 

		REP(i, 0, q) {
			cin >> a;
			if (a == 1) {
				cin >> b >> c;
				A[b - 1] = MP(c, i); // update this person
			}
			else {
				cin >> b;
				payout[i] = b; // update the payout timeline
			}
		}

		// max-suffix
		RREP(i, q - 2, 0) {
			payout[i] = max(payout[i], payout[i + 1]);
		}

		REP(i, 0, n) {
			cout << max(A[i].first, payout[A[i].second + 1]) << ' ';
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