/*
Original problem: https://codeforces.com/problemset/problem/1203/B
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
		VI A(n * 4);
		REP(i, 0, n * 4) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		// check they come in pairs
		REP(i, 0, 2 * n) {
			if (A[2 * i] != A[2 * i + 1]) {
				cout << "NO" << endl;
				return;
			}
		}

		// check they all prod to same area
		int og = A[0] * A[4 * n - 1];
		REP(i, 0, 2 * n) {
			if (A[i] * A[4 * n - i - 1] != og) {
				cout << "NO" << endl;
				return;
			}
		}

		cout << "YES" << endl;
        
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