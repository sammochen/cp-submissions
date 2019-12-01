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

const ll inf = 1e9+7;

namespace SOLVE {	
	void show(VVLL & grid) {
		REP(i,0,3) {
			REP(j,0,3) {
				cout << " ";
				if (grid[i][j] == 0) cout << i * 3 + j;
				else if (grid[i][j] == 1) cout << "O";
				else if (grid[i][j] == 2) cout << "X";
				if (j != 2) cout << " |";
			}
			cout << endl;
			if (i != 2) cout << "-----------" << endl;
		}
	}

	PLL value(VVLL grid, ll turn, ll fullness) {
		if (fullness == 9) return {0, -1}; // draw is 0!

		ll best = -1; // start with the worst outcome - lose in 1
		ll pos = -1;

		REP(i,0,3) {
			REP(j,0,3) {
				if (grid[i][j] != 0) continue;

				VVLL copy = grid;
				copy[i][j] = turn;

				// if it makes three in a row
				ll h = 1, v = 1, d1 = 1, d2 = 1;
				REP(k,0,3) {
					if (copy[i][k] != turn) v = 0;
					if (copy[k][j] != turn) h = 0;
					if (copy[k][k] != turn) d1 = 0;
					if (copy[2-k][k] != turn) d2 = 0;
				}

				if (h || v || d1 || d2) return {fullness + 1, 3 * i + j}; // win in 1 move

				// three possible outcomes
				// i prefer winning, and winning small
				// i then prefer to draw
				// i then will lose, but will drag it out

				ll thisvalue = -value(copy, 3 - turn, fullness + 1).first;
				ll update = 0;

				if (thisvalue > 0) { // if i win 
					if (best > 0) { // if already was winning, update if smaller
						if (thisvalue < best) {
							update = 1;
						}
					} else { // if i was losing or drawing, update
						update = 1;
					}
				} else if (thisvalue == 0) { // if draw, only update if it was losing
					if (best < 0) {
						update = 1;
					} 
				} else if (thisvalue < 0) { // if this is losing, only update if was losing and was closer
					if (best < 0) {
						if (thisvalue < best) {
							update = 1;
						}
					}
				}

				if (update) {
					best = thisvalue;
					pos = 3 * i + j;
				}				
			}
		}
		return {best, pos};
	}

	void main() {
		VVLL grid(3, VLL(3));
		ll turn = 2, fullness = 0;
		while (fullness != 9) {
			show(grid);
			ll pos;
			if (turn == 1) {
				cin >> pos;
			} else {
				pos = value(grid, turn, fullness).second;
			}
			grid[pos / 3][pos % 3] = turn;

			turn = 3 - turn;
			fullness++;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
