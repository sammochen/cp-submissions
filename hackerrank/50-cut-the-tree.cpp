/*
Original problem: https://www.hackerrank.com/challenges/cut-the-tree
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define MP make_pair

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	int n;
	VI values;
	vector<VI> E; // stores a pair: (to, weight)
	int ans = 1e9 + 7, graphw = 0;

	// finds the subtree from v downwards, rooted at 1
	int subtree(int v, int prev) {
		int total = values[v];
		for (int e : E[v]) {
			if (e != prev) {
				total += subtree(e, v);
			}
		}
		ans = min(ans, abs(graphw - 2 * total));
		return total;
	}

	void main() {
		// strategy: find the subtree value that is closest to graphw / 2
		int a, b;
		cin >> n;
		E.resize(n + 1);
		values.resize(n + 1);

		REP(i, 0, n) {
			cin >> values[i + 1];
			graphw += values[i + 1];
		}

		REP(i, 0, n - 1) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		// dfs rooted at 1
		subtree(1, 0);
		
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