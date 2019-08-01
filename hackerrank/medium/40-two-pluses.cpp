/*
Original problem: https://www.hackerrank.com/challenges/two-pluses
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
	// brute force solution - try place a plus in any available square, then try place another one.
	int n, m, ans;

	// i will solve this recursively! 
	void r(vector<string> grid, VI prev) {
		// maximum 2 pluses
		if (prev.size() == 2) {
			ans = max(ans, prev[0] * prev[1]);
			return;
		}

		REP(i, 0, n) {
			REP(j, 0, m) {
				// we are currently in grid[i][j]. we look for any plus and recur!
				int biggest = min(min(n - i - 1, i), min(m - j - 1, j)); // max plus that could be here (otherwise index error)

				int di[4] = { 0,0,1,-1 };
				int dj[4] = { 1,-1,0,0 };

				vector<string> tempgrid = grid;
				REP(side, 0, biggest + 1) { // from 0 to big, see if the space is good
					VI tempprev = prev;
					int good = 1;

					REP(direction, 0, 4) {
						int ii = i + side * di[direction];
						int jj = j + side * dj[direction];

						if (grid[ii][jj] == 'B') {
							good = 0;
							break;
						}
						tempgrid[ii][jj] = 'B';
					}
					if (good) {
						// if the plus fits, call r and try this new combination
						tempprev.push_back(side * 4 + 1);
						r(tempgrid, tempprev);
					}
					else {
						break;
					}
				}
			}
		}


	}
	void main() {
		cin >> n >> m;
		vector<string> grid(n);
		REP(i, 0, n) {
			cin >> grid[i];
		}

		r(grid, VI(0));
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