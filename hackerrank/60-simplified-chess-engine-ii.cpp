/*
Original problem:
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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

void in(char & c) {
	ll a = scanf(" %c", &c);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll getcol(char col) {
		string s = "ABCD";
		REP(i,0,4) {
			if (s[i] == col) return i;
		}
		return -1;
	}

	ll getrow(ll row) {
		return 4 - row;
	}

	ll hash(char piece) {
		string pos = "QRBNP";
		REP(i,0,5) {
			if (pos[i] == piece) return i;
		}
		debug("not supposed to happen");
		exit(1);
	}

	set<PLL> rookmoves(VVLL & grid, ll i, ll j) {
		set<PLL> ans;

		VLL di = {-1,1,0,0};
		VLL dj = {0,0,-1,1};
	
		REP(x,0,4) {
			REP(steps,1,5) {
				ll ii = i + di[x] * steps;
				ll jj = j + dj[x] * steps;
				// if it goes out, or if it hits itself, stop
				if (ii < 0 || ii >= 4 || jj < 0 || jj >= 4) break;
				if (grid[ii][jj] != -1 && grid[i][j] % 2 == grid[ii][jj] % 2) break; // same colour
				ans.insert({ii,jj});
				// if it is a different colour, stop
				if (grid[ii][jj] != -1) break;
			}
		}
		return ans;
	}

	set<PLL> bishopmoves(VVLL & grid, ll i, ll j) {
		set<PLL> ans;

		VLL di = {-1,1,-1,1};
		VLL dj = {-1,-1,1,1};
	
		REP(x,0,4) {
			REP(steps,1,5) {
				ll ii = i + di[x] * steps;
				ll jj = j + dj[x] * steps;
				// if it goes out, or if it hits itself, stop
				if (ii < 0 || ii >= 4 || jj < 0 || jj >= 4) break;
				if (grid[ii][jj] != -1 && grid[i][j] % 2 == grid[ii][jj] % 2) break; // same colour
				ans.insert({ii,jj});
				// if it is a different colour, stop
				if (grid[ii][jj] != -1) break;
			}
		}
		return ans;
	}

	set<PLL> queenmoves(VVLL & grid, ll i, ll j) {
		set<PLL> ans;
		for (PLL r : rookmoves(grid,i,j)) ans.insert(r);
		for (PLL b : bishopmoves(grid,i,j)) ans.insert(b);
		return ans;
	}

	set<PLL> knightmoves(VVLL & grid, ll i, ll j) {
		set<PLL> ans;
		VLL di = {1,2,2,1,-1,-2,-2,-1};
		VLL dj = {2,1,-1,-2,-2,-1,1,2};
		REP(x,0,8) {
			ll ii = i + di[x];
			ll jj = j + dj[x];

			if (ii < 0 || ii >= 4 || jj < 0 || jj >= 4) continue;
			if (grid[ii][jj] == -1 || (grid[i][j] % 2 != grid[ii][jj] % 2)) ans.insert({ii,jj});
		}
		return ans;
	}

	set<PLL> pawnmoves(VVLL & grid, ll i, ll j) {
		set<PLL> ans;
		ll ii = grid[i][j] % 2 == 0 ? i-1 : i+1;

		if (ii < 0 || ii >= 4) return ans;
		if (grid[ii][j] == -1) ans.insert({ii, j});
		if (j + 1 < 4 && grid[ii][j+1] != -1 && grid[ii][j+1] % 2 != grid[i][j] % 2) ans.insert({ii, j+1});
		if (j - 1 >= 0 && grid[ii][j-1] != -1 && grid[ii][j-1] % 2 != grid[i][j] % 2) ans.insert({ii, j-1});
		return ans;
	}

	set<PLL> getmoves(VVLL & grid, ll i, ll j) {
		if (grid[i][j] == -1) return {};
		if (grid[i][j] / 2 == 0) return queenmoves(grid,i,j);
		if (grid[i][j] / 2 == 1) return rookmoves(grid,i,j);
		if (grid[i][j] / 2 == 2) return bishopmoves(grid,i,j);
		if (grid[i][j] / 2 == 3) return knightmoves(grid,i,j);
		if (grid[i][j] / 2 == 4) return pawnmoves(grid,i,j);
		return {};
	}

	// 1 if win, 0 if lose
	ll win(VVLL & grid, ll turn, ll k) {
		if (k == 0) {
			if (turn == 0) return 0;
			if (turn == 1) return 1;
		}
		if (k == 1 && turn == 1) return 1;
		ll best = -1;

		REP(i,0,4) {
			REP(j,0,4) {
				if (grid[i][j] == -1) continue;

				if (grid[i][j] % 2 == turn) {
					set<PLL> moves = getmoves(grid,i,j);
					for (PLL move : moves) {
						ll src = grid[i][j];
						ll target = grid[move.first][move.second];

						if (grid[move.first][move.second] != -1 && grid[move.first][move.second] / 2 == 0) return 1;

						// have to check for special pawn case
						if (grid[i][j] / 2 == 4 && (move.first == 0 || move.first == 3)) {
							VLL promote = {1,2,3};
							REP(promotepiece,0,3) {
								grid[move.first][move.second] = promote[promotepiece] * 2 + turn;
								grid[i][j] = -1;
								
								best = max(best, -win(grid, 1 - turn, k-1));

								grid[move.first][move.second] = target;
								grid[i][j] = src;

								if (best == 1) return 1;
							}
						// otherwise, simple move
						} else {
							grid[move.first][move.second] = grid[i][j]; 
							grid[i][j] = -1;

							best = max(best, -win(grid, 1 - turn, k-1));

							grid[move.first][move.second] = target;
							grid[i][j] = src;

							if (best == 1) return 1;
						}
					}
				}
			}
		}
		return best;
	}

	void main() {
		ll w, b, m;
		cin >> w >> b >> m;
		if (m % 2 == 0) m--;

		VVLL grid(4, VLL(4, -1));
		

		REP(i,0,w) {
			char piece, col;
			ll row;
			cin >> piece >> col >> row;
			grid[getrow(row)][getcol(col)] = 2 * hash(piece);
		}

		REP(i,0,b) {
			char piece, col;
			ll row;
			cin >> piece >> col >> row;
			grid[getrow(row)][getcol(col)] = 2 * hash(piece) + 1;
		}

		ll ans = win(grid, 0, m);
		if (ans == 1) printf("YES\n");
		else printf("NO\n");
	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
