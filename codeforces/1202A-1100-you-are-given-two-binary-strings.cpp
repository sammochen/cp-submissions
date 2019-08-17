/*
Original problem: https://codeforces.com/problemset/problem/1202/A
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
        string a, b;
		cin >> a >> b;
		if (b == "0") {
			cout << 0 << endl;
			return;
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int ai = -1, bi = -1;

		// find first b 1
		REP(i,0,b.length()) {
			if (b[i] == '1') {
				bi = i;
				break;
			}
		}

		// find first a 1 thats >= bi
		REP(i,bi,a.length()) {
			if (a[i] == '1') {
				ai = i;
				break;
			}
		}

		int ans = ai == -1 ? 0 : ai - bi;
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