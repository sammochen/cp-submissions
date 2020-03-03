/*
Original problem: https://codeforces.com/problemset/problem/1197/A
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
		VI A(n);
		REP(i,0,n) {
			cin >> A[i];
		}
		sort(A.rbegin(), A.rend());
		int ans = min(A[1] - 1, n - 2);
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