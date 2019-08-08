/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_v
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

ll mod;

namespace SOLVE {
	ll mult(ll a, ll b) {
		return (a * b) % mod;
	}

	vector<VI> E; // E[a] contains all neighbours of a
	vector<VI> pre; // pre[a][i] is mult product of all up to ith a-neighbour - excl. parent
	vector<VI> suf; // suf[a][i] same, but from ith a-neighbour onwards - excl. parent

	VI p; // p[i]: parent of i when tree is rooted at 1

	// these two VI supports O(1) products
	VI subtree; // subtree[i]: how many ways the subtree can be black given that i is black
	VI supertree; // supertree[i]: for supertree, given that i is black.
	int root = 1;
	
	// subtree
	void subdfs(int a, int prev) {
		subtree[a] = 1;
		p[a] = prev;

		for (int b: E[a]) {
			if (b != prev) {
				subdfs(b, a);
				subtree[a] = mult(subtree[a], (1 + subtree[b]));
			}
		}
		
		// works out pre and sub
		pre[a] = E[a];
		suf[a] = E[a];

		REP(i, 0, E[a].size()) {
			if (E[a][i] != prev) {
				pre[a][i] = subtree[E[a][i]] + 1;
				suf[a][i] = subtree[E[a][i]] + 1;
			} else {
				// excludes parent! important
				pre[a][i] = 1;
				suf[a][i] = 1;
			}
		}

		for (int i = 1; i < E[a].size(); i++) {
			pre[a][i] = mult(pre[a][i], pre[a][i - 1]);
		}

		for (int i = E[a].size() - 2; i >= 0; i--) {
			suf[a][i] = mult(suf[a][i], suf[a][i + 1]);
		}

	}

	// supertree
	void superdfs(int a, int prev, int index) { 
		// supertree[i] = supertree[p[i]] * product(p[i]'s other children's subtrees)
		if (prev == -1) {
			supertree[a] = 1;
		} else {
			supertree[a] = supertree[prev];
			if (index != 0) {
				supertree[a] = mult(supertree[a], pre[prev][index - 1]);
			}
			if (index != E[prev].size() - 1) {
				supertree[a] = mult(supertree[a], suf[prev][index + 1]);
			}
			supertree[a]++;
		}

		for (int i = 0; i < E[a].size(); i++) {
			int b = E[a][i];
			if (b != prev) {
				superdfs(b, a, i);
			}
		}
	}

	void main() {
		int n, a, b;
		cin >> n >> mod;

		E.resize(n + 1);
		p.resize(n + 1);
		pre.resize(n + 1);
		suf.resize(n + 1);
		subtree.resize(n + 1);
		supertree.resize(n + 1);
		
		REP(i, 0, n - 1) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		// work out subtree
		subdfs(root, -1);
		// work out supertree
		superdfs(root, -1, -1);
		
		REP(i, 1, n + 1) {
			int ans = mult(subtree[i], supertree[i]); // ans is all combinations of sub and super
			cout << ans << endl;
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