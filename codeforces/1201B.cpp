/*
Original problem: https://codeforces.com/contest/1201/problem/B
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
	void main() {
		int n;
		cin >> n;
		VLL A(n);

		ll total = 0;
		REP(i, 0, n) {
			cin >> A[i];
			total += A[i];
		}

		if (total % 2 == 1) {
			cout << "NO" << endl;
			return;
		}

		ll toobig = total / 2 + 1;
		REP(i, 0, n) {
			if (A[i] >= toobig) {
				cout << "NO" << endl;
				return;
			}
		}

		cout << "YES" << endl;
		return;
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