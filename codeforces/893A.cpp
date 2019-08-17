/*
Original problem: https://codeforces.com/problemset/problem/893/A
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

const ll mod = 1e9+7;

namespace SOLVE {
    void main() {
        int n, x;
		cin >> n;

		VI play(3);
		play[1] = 1;
		play[2] = 1;

		REP(i,0,n) {
			cin >> x;
			x %= 3;
			if (play[x] == 0) {
				cout << "NO" << endl;
				return;
			}
			play[(x + 1) % 3] ^= 1;
			play[(x + 2) % 3] ^= 1;
		}

		cout << "YES" << endl;
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