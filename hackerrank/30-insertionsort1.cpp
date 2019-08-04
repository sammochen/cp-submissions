/*
Original problem: https://www.hackerrank.com/challenges/insertionsort1
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

const int inf = 1e9 + 7;

namespace SOLVE {
	void print(VI x) {
		for (int xx : x) {
			cout << xx << ' ';
		}
		cout << endl;
	}

	void main() {
		int n;
		cin >> n;
		VI A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		// as said in the question, have a hold and slot it in when it is larger than the next one.
		// careful - when i is 0, you have to slot it in
		int hold = A[n - 1];
		for (int i = n - 1; i >= 0; i--) {
			if (i != 0 && hold < A[i - 1]) {
				A[i] = A[i - 1];
			}
			else {
				A[i] = hold;
				hold = inf;
			}
			print(A);
			if (hold == inf) {
				break;
			}
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