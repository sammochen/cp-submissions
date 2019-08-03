/*
Original problem: https://www.hackerrank.com/challenges/jeanies-route
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
	int n, k;
	vector<vector<PII>> E; // stores a pair: (to, weight)
	vector<vector<PII>> subtreeE; // also stores a pair. this tree is the smallest subtree that has all the cities

	VI lettercity; // O(1) of whether a city is a letter

	// returns the number of lettercities from v's subtree
	int fillsubtree(int v, int prev) {
		int total = lettercity[v];
		for (PII e : E[v]) {
			if (e.first != prev) {
				int sub = fillsubtree(e.first, v);
				if (sub != 0) {
					// keep this edge!
					subtreeE[v].push_back(MP(e.first, e.second));
					subtreeE[e.first].push_back(MP(v, e.second));
					total += sub;
				}
			}
		}
		return total;
	}

	int totalw; // total weight
	int maxd; // max distance
	int farv; // furthest city

	// dfs from the subtreeE edges
	// can determine total weight and furthest node and maximum distance of the node
	void subtreedfs(int v, int prev, int d) {
		if (d > maxd) {
			maxd = d;
			farv = v;
		}
		for (PII e : subtreeE[v]) {
			if (e.first != prev) {
				totalw += e.second;
				subtreedfs(e.first, v, d + e.second);
			}
		}
	}

	void main() {
		// strategy: find a subtree that has all the lettercities
		// i can do this by doing a dfs and seeing if i want to keep the edge

		int a, b, c; // temps
		int startcity; // i will always make my tree start from a required city

		cin >> n >> k;
		E.resize(n + 1);
		subtreeE.resize(n + 1);
		lettercity.resize(n + 1);

		REP(i, 0, k) {
			cin >> a;
			lettercity[a] = 1;
			startcity = a;
		}

		REP(i, 0, n - 1) {
			cin >> a >> b >> c;
			E[a].push_back(MP(b, c));
			E[b].push_back(MP(a, c));
		}
		
		// this finds the subtree from the startcity
		fillsubtree(startcity, 0);
		
		// by now, my subtree has been made. i need to find the total weight of this tree and the diameter
		// the answer is 2 * w - d

		// first dfs: look for furthest node
		totalw = 0;
		maxd = 0;
		farv = -1;
		subtreedfs(startcity, 0, 0);
		
		totalw = 0;
		maxd = 0;
		subtreedfs(farv, 0, 0);

		cout << 2 * totalw - maxd << endl;

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