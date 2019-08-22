/*
Original problem: https://codeforces.com/problemset/problem/1200/A
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
        string s;
		cin >> n >> s;
		VI rooms(10);
		for (char c : s) {
			if (c == 'L') {
				REP(i,0,10) {
					if (rooms[i] == 0) {
						rooms[i] = 1;
						break;
					}
				}
			} else if (c == 'R') {
				RREP(i,9,0) {
					if (rooms[i] == 0) {
						rooms[i] = 1;
						break;
					}
				}
			} else {
				rooms[c - '0'] = 0;
			}
		}

		REP(i,0,10) {
			cout << rooms[i];
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