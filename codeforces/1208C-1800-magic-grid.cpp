/*
Original problem: https://codeforces.com/problemset/problem/1208/C
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

		int x = 0;
		vector<VI> ans(n, VI(n));

		for (int i = 0; i < n; i += 4) {
			for (int j = 0; j < n; j += 4) {
				REP(ii,0,4) {
					REP(jj,0,4) {
						ans[i + ii][j + jj] = x++;
					}
				}
			}
		}

		REP(i,0,n) {
			REP(j,0,n) {
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
    }
}


signed main() {
	int t;
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
