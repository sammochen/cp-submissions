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

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll all(VLL A) {
		VLL f(3);
		REP(i,0,4) f[A[i]]++;
		if (f[1] == 4) return 1;
		if (f[2] == 4) return 2;
		return 0;
	}
	// 0 if draw, 1 if 1 row, 2 if 2 row, 3 if continue
	ll check(VVLL grid) {
		ll anything = 0;
		REP(i,0,4) {
			VLL h(4), v(4);
			REP(j,0,4) {
				h[j] = grid[i][j];
				v[j] = grid[j][i];
				anything |= grid[i][j];
			}
			if (all(h)) return h[0];
			if (all(v)) return v[0];
		}

		VLL d1(4), d2(4);
		REP(i,0,4) {
			d1[i] = grid[i][i];
			d2[i] = grid[i][3-i];
		}

		if (all(d1)) return d1[0];
		if (all(d2)) return d2[0];

		if (anything) return 3;
		else return 0;
	}

	map<VVLL,ll> dp;
	map<VVLL,ll> done;

	// 0 if draw, 1 if 1 wins, 2 if 2 wins
	ll win(VVLL grid, ll turn) {
		if (done[grid]) return dp[grid];
		ll status = check(grid);
		if (status != 3) {
			done[grid] = 1;
			dp[grid] = status;
			return status;
		}

		VLL freq(3);
		REP(i,0,4) {
			REP(j,0,4) {
				if (grid[i][j] == 0) {
					VVLL next = grid;
					next[i][j] = turn;
					freq[win(next, 3-turn)]++;
				}
			}
		}
		ll ans;
		if (freq[turn]) ans = turn;
		else if (freq[0]) ans = 0;
		else ans = 3 - turn;

		done[grid] = 1;
		dp[grid] = ans;
		return ans;
	}

	void main() {
		string s;
		while (cin >> s, s == "?") {
			VVLL grid(4, VLL(4));
			REP(i,0,4) {
				cin >> s;
				REP(j,0,4) grid[i][j] = s[j] == '.' ? 0 : s[j] == 'x' ? 1 : 2;
			}
			debug(grid);

			ll ok = 0;
			REP(i,0,4) {
				REP(j,0,4) {
					if (grid[i][j] != 0) continue;
					
					VVLL next = grid;
					next[i][j] = 1;
					if (win(next, 2) == 1) {
						cout << "(" << i << "," << j << ")" << endl;
						ok = 1;
					}
					if (ok) break;
				}
				if (ok) break;
			}
			if (!ok) cout << "#####" << endl;
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
