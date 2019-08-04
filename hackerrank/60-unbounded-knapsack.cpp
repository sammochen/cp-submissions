/*
Original problem: https://www.hackerrank.com/challenges/unbounded-knapsack
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
		// strategy: the low constraints (n, k <= 2000) mean that we can use a O(nk) algorithm
		// for every number i and value v, check if i - v is possible. if so, i is possible

		int n, k;
		cin >> n >> k;

		VI A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		int ans;
		VI poss(k + 1);
		poss[0] = 1;
		REP(i, 1, k + 1) {
			for (int v : A) {
				if (i - v >= 0 && poss[i - v] == 1) {
					poss[i] = 1;
					ans = i;
					break;
				}
			}
		}

		cout << ans << endl;
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