/*
Original problem: https://www.hackerrank.com/challenges/stockmax
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

namespace SOLVE {

	void main() {
		// strategy: each number provides a value only if there is a number that is larger afterwards
		// if i iterate backwards and keep track of the largest number M, the difference is M - A[i]

		int n;
		cin >> n;
		VLL A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		ll M = 0;
		ll ans = 0;
		// go from backwards forward 
		RREP(i, n - 1, 0) {
			if (A[i] > M) {
				M = A[i];
			} 
			else {
				ans += (M - A[i]);
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