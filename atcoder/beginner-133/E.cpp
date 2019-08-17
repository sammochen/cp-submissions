/*
Original problem: https://atcoder.jp/contests/abc133/tasks/abc133_e
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
	int n, k;
	ll ans = 1;
	vector<VI> E;

	ll mul(ll& a, ll b) {
		a = (a * b) % mod;
	}

	void dfs(int a, int prev) {
		int m = prev == -1 ? k - 1 : k - 2;

		for (int b : E[a]) {	
			if (b != prev) {
				mul(ans, m);
				m--;

				dfs(b, a);
			}
		}
	}

    void main() {
		cin >> n >> k;
		E.resize(n+1);
		int a, b;
		REP(i,0,n-1) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		// do a dfs! i will multiply BEFORE i go in
		mul(ans, k);
		dfs(1, -1);
		
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