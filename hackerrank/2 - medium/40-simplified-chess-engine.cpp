/*
Original problem: https://www.hackerrank.com/challenges/simplified-chess-engine
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
typedef vector<vector<string>> VVS;

namespace SOLVE {
	const int ME = 1, YOU = -1, UNSURE = 0; // arbitrary state values
	const string EMPTY = "--";
	int n = 4;

	// in the grid!
	int valid(int i, int j) {
		return (i >= 0 && i < n && j >= 0 && j < n);
	}

	// four helper functions that returns an array of possible moves for each piece

	vector<PII> knight(VVS grid, PII pos) {
		char itself = grid[pos.first][pos.second][0];
		vector<PII> ans;

		int di[8] = { -2,-2,-1,-1,1,1,2,2 };
		int dj[8] = { 1,-1,2,-2,2,-2,1,-1 };

		REP(i, 0, 8) {
			int ii = pos.first + di[i];
			int jj = pos.second + dj[i];
			if (valid(ii, jj) && grid[ii][jj][0] != itself) {
				ans.push_back(MP(ii, jj));
			}
		}
		return ans;
	}

	vector<PII> rook(VVS grid, PII pos) {
		char itself = grid[pos.first][pos.second][0];
		char edible = itself == 'B' ? 'W' : 'B';
		vector<PII> ans;

		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };

		REP(direction, 0, 4) {
			REP(steps, 1, n) {
				int ii = pos.first + di[direction] * steps;
				int jj = pos.second + dj[direction] * steps;
				if (!valid(ii, jj)) {
					break;
				}
				if (grid[ii][jj][0] == itself) {
					break;
				}
				if (grid[ii][jj][0] == edible) {
					ans.push_back(MP(ii, jj));
					break;
				}
				ans.push_back(MP(ii, jj));
			}
		}
		return ans;
	}

	vector<PII> bishop(VVS grid, PII pos) {
		char itself = grid[pos.first][pos.second][0];
		char edible = itself == 'B' ? 'W' : 'B';
		vector<PII> ans;

		int di[4] = { 1,-1,1,-1 };
		int dj[4] = { 1,-1,-1,1 };

		REP(direction, 0, 4) {
			REP(steps, 1, n) {
				int ii = pos.first + di[direction] * steps;
				int jj = pos.second + dj[direction] * steps;
				if (!valid(ii, jj)) {
					break;
				}
				if (grid[ii][jj][0] == itself) {
					break;
				}
				if (grid[ii][jj][0] == edible) {
					ans.push_back(MP(ii, jj));
					break;
				}
				ans.push_back(MP(ii, jj));
			}
		}
		return ans;
	}

	vector<PII> queen(VVS grid, PII pos) {
		vector<PII> b = bishop(grid, pos);
		vector<PII> r = rook(grid, pos);
		for (PII x : r) {
			b.push_back(x);
		}
		return b;
	}

	// returns 1 if the piece at pos is edible by some other piece
	int danger(VVS grid, PII pos) {
		char itself = grid[pos.first][pos.second][0];
		char edible = itself == 'B' ? 'W' : 'B';

		// i will see if any of the Q, B, R, N can attack this square
		vector<PII> r = rook(grid, pos);
		for (PII rr : r) {
			if (grid[rr.first][rr.second][0] == edible) {
				if (grid[rr.first][rr.second][1] == 'R' || grid[rr.first][rr.second][1] == 'Q') {
					return 1;
				}
			}
		}

		vector<PII> b = bishop(grid, pos);
		for (PII bb : b) {
			if (grid[bb.first][bb.second][0] == edible) {
				if (grid[bb.first][bb.second][1] == 'B' || grid[bb.first][bb.second][1] == 'Q') {
					return 1;
				}
			}
		}

		vector<PII> n = knight(grid, pos);
		for (PII nn : n) {
			if (grid[nn.first][nn.second][0] == edible) {
				if (grid[nn.first][nn.second][1] == 'N') {
					return 1;
				}
			}
		}
		return 0;
	}

	// returns the state of current grid
	// WHITE if white wins, BLACK if black wins and UNSURE if unsure :)
	int state(VVS grid, char player, int movesleft) {
		// cheeky prune
		if (movesleft == 1 && player == 'B') {
			return UNSURE;
		}
		if (movesleft == 0) {
			return UNSURE;
		}
		
		// check if your queen is in danger - immediate win if so
		PII yourqueen;
		REP(i, 0, n) {
			REP(j, 0, n) {
				if (grid[i][j][0] != player && grid[i][j][1] == 'Q') {
					yourqueen = MP(i, j);
				}
			}
		}
		if (danger(grid, yourqueen)) {
			// we won!
			return ME;
		}
		
		int total = 0;
		int mywins = 0;
		int yourwins = 0;

		// for each square on the board,
		REP(i, 0, n) {
			REP(j, 0, n) {
				// if the piece if ours,
				if (grid[i][j][0] == player) {
					// determine the moves it can do
					vector<PII> moves;
					if (grid[i][j][1] == 'Q') {
						moves = queen(grid, MP(i, j));
					}
					if (grid[i][j][1] == 'B') {
						moves = bishop(grid, MP(i, j));
					}
					if (grid[i][j][1] == 'N') {
						moves = knight(grid, MP(i, j));
					}
					if (grid[i][j][1] == 'R') {
						moves = rook(grid, MP(i, j));
					}

					for (PII move : moves) {
						// the result of the next move
						int result;
						// if we can capture a queen, we win
						if (grid[move.first][move.second][1] == 'Q') {
							// in the next move, YOU is us (confusing!)
							result = YOU;
						}
						else {
							VVS newgrid = grid;
							newgrid[move.first][move.second] = grid[i][j];
							newgrid[i][j] = EMPTY;
							result = state(newgrid, player == 'B' ? 'W' : 'B', movesleft - 1);
						}
						// see how many of the total possibilities we win and lose
						mywins += result == YOU;
						yourwins += result == ME;
						total += 1;

						// if we can win any by force, we win
						// pruning
						if (mywins >= 1) {
							return ME;
						}
					}
				}
			}
		}
	
		// we will lose if every move leads to them winning
		return yourwins == total ? YOU : UNSURE;
	}


	void main() {
		// strategy - solve recursively - be careful not to go into unnecessary states
		// there may more more elaborate prunes but this was enough to pass all tests on hackerrank
		int w, b, m;
		string x, y;
		int z;
		VVS grid(n, vector<string>(n, EMPTY));
		
		cin >> w >> b >> m;

		// initialise the grid
		REP(white, 0, w) {
			cin >> x >> y >> z;
			int ii = n - z;
			int jj = (y[0] - 'A');
			grid[ii][jj] = "W" + x;
		}

		REP(black, 0, b) {
			cin >> x >> y >> z;
			int ii = n - z;
			int jj = (y[0] - 'A');
			grid[ii][jj] = "B" + x;
		}

		// if we can win, yes, otherwise no
		if (state(grid, 'W', m) == ME) {
			cout << "YES" << endl;
			return;
		}
		cout << "NO" << endl;
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