/*
Original problem: https://atcoder.jp/contests/abc135/tasks/abc135_b
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
        int n, d = 0, temp;
		cin >> n;
		
		REP(i,0,n) {
			cin >> temp;
			if (temp != i+1) {
				d++;
			}
		}
		if (d == 0 || d == 2) cout << "YES" << endl;
		else cout << "NO" << endl;
		
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