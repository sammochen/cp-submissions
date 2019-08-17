/*
Original problem: https://codeforces.com/problemset/problem/1203/A
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
	int mod(int x, int m) {
		while (x < 0) {
			x += m;
		}
		return x % m;
	}

    void main() {
        int n;
		cin >> n;

		VI A(n);
		REP(i,0,n) {
			cin >> A[i];
		}

		int one;
		REP(i,0,n) {
			if (A[i] == 1) {
				one = i;
			}
		}

		int f = 1;
		REP(i,0,n) {
			if (A[mod(one+i, n)] != 1 + i) {
				f = 0;
			}
		}

		int b = 1;
		REP(i,0,n) {
			if (A[mod(one-i, n)] != 1 + i) {
				b = 0;
			}
		}

		if (f || b) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

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