/*
Original problem: https://atcoder.jp/contests/abc134/tasks/abc134_d
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
        int n;
		cin >> n;
		VI A(n + 1);
		REP(i,1,n+1){
			cin >> A[i];
		}

		int onecount = 0;
		VI ans(n + 1);
		RREP(i, n, 1) {
			int c = 0;
			// check forward and see what had been set
			for (int mult = 2 * i; mult <= n; mult += i) {
				c += ans[mult];
			}
			c %= 2;
			ans[i] = c != A[i];
			if (ans[i] == 1) {
				onecount++;
			}
		}

		cout << onecount << endl;
		REP(i, 1, n+1) {
			if (ans[i] == 1) {
				cout << i << ' ';
			}
		}
		cout << endl;
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