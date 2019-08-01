/*
Original problem: https://www.hackerrank.com/challenges/misere-nim-1
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
		// strategy: the game is dependent solely one the total xor and whether it is full of ones

		int n, temp;
		int onesonly = 1;
		int xortotal = 0;
		cin >> n;
		REP(i, 0, n) {
			cin >> temp;
			xortotal ^= temp;
			if (temp != 1) {
				onesonly = 0;
			}
		}
		if (xortotal == 0) {
			if (onesonly && n % 2 == 0) {
				cout << "First" << endl;
			}
			else {
				cout << "Second" << endl;
			}
		}
		else {
			if (onesonly && n % 2 == 1) {
				cout << "Second" << endl;
			}
			else {
				cout << "First" << endl;
			}
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