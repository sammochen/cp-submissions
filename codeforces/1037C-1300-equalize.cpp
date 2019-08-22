/*
Original problem: https://codeforces.com/problemset/problem/1037/C
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

		string a, b;
		cin >> a >> b;

		int ans = 0;
		REP(i,0,n) {
			if (i != n - 1 && a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
				ans++;
				a[i + 1] = b[i + 1];
			} else if (a[i] != b[i]) {
				ans++;
			}
		}
		cout << ans << endl;
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