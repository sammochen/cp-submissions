/*
Original problem: https://codeforces.com/problemset/problem/1198/D
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)


#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	const int nax = 51, inv = -1;
	int n;
	int dp[nax][nax][nax][nax]; // dp[a][b][c][d] holds the least cost to cover the grid from grid[a][b] to grid[c][d]
	vector<string> grid;	

	void initdp() { // 
		REP(a, 0, n) {
			REP(b, 0, n) {
				REP(c, 0, n) {
					REP(d, 0, n) {
						dp[a][b][c][d] = inv;
					}
				}
			}
		}
	}

	// finds the min cost if only considering a,b to c,d, inclusive
	int cost(int a, int b, int c, int d) {
		// invalid case
		if (c < a || d < b) {
			return 0;
		}
		// base case
		if (a == c && b == d) {
			return grid[a][b] == '#';
		}
		// memoisation
		if (dp[a][b][c][d] != inv) {
			return dp[a][b][c][d];
		}

		// choose a splitting point! no split: simply one rectangle
		int best = max(c - a + 1, d - b + 1);

		// split vertically into two rectangles
		for (int i = a; i < c; i++) {
			int thiscost = cost(a, b, i, d) + cost(i + 1, b, c, d);
			best = min(best, thiscost);
		}

		// split horizontally into two rectangles
		for (int j = b; j < d; j++) {
			int thiscost = cost(a, b, c, j) + cost(a, j + 1, c, d);
			best = min(best, thiscost);
		}

		dp[a][b][c][d] = best;
		return best;
	}

	void main() {
		cin >> n;
		grid.resize(n);

		REP(i, 0, n) {
			cin >> grid[i];
		}

		initdp();

		// there are O(n^4) entries and each one is O(n) to work out
		// total complexity: O(n^5)
		cout << cost(0, 0, n - 1, n - 1);
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