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
	ll n, m;
	ll count = 0;
	ll good = 1;
	ll x, y;
	char land;

	void dfs(ll i, ll j, vector<string> & grid, VVLL & visited) {
		if (i < 0 || i >= n || j < 0 || j >= m) return;
		if (visited[i][j]) return;
		if (grid[i][j] != land) return;
		if (i == x && j == y) good = 0;
		count++;
		visited[i][j] = 1;
		
		VLL di = {0,0,1,-1};
		VLL dj = {1,-1,0,0};
		REP(x,0,4) {
			dfs(i + di[x], (j + dj[x] + m) % m, grid, visited);
		}
	}
	void main() {
		while (cin >> n >> m) {
			vector<string> grid(n);
			VVLL visited(n, VLL(m));

			REP(i,0,n) cin >> grid[i];

			cin >> x >> y;
			land = grid[x][y];

			ll ans = 0;
			REP(i,0,n) {
				REP(j,0,m) {
					if (!visited[i][j]) {
						count = 0;
						good = 1;
						dfs(i, j, grid, visited);
						if (good) {
							ans = max(ans, count);
						}
					}
				}
			}

			cout << ans << endl;
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
