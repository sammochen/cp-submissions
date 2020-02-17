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
	ll same(char a, char b) {
		if (a == b) return 1;
		if (b > a) b -= ('a' - 'A');
		else a -= ('a' - 'A');
		return a == b;
	}
	ll exist(vector<string> & grid, string & s, ll i, ll j, ll di, ll dj) {
		REP(x,0,s.length()) {
			ll ii = i + di * x;
			ll jj = j + dj * x;
			if (ii < 0 || ii >= grid.size() || jj < 0 || jj >= grid[0].length()) return 0;
			if (!same(grid[ii][jj], s[x])) return 0;
		}
		return 1;
	}
	PLL look(vector<string> & grid, string & s) {
		VLL di = {0,1,1,1,0,-1,-1,-1};
		VLL dj = {-1,-1,0,1,1,1,0,-1};
		REP(i,0,grid.size()) {
			REP(j,0,grid[0].length()) {
				REP(x,0,8) {
					if (exist(grid, s, i, j, di[x], dj[x])) {
						return {i + 1, j + 1};
					}
				}
			}
		}
	}
	void main() {
		ll n, m;
		cin >> n >> m;
		vector<string> grid(n);
		REP(i,0,n) {
			cin >> grid[i];
		}

		ll q;
		cin >> q;
		REP(qq,0,q) {
			string s;
			cin >> s;
			PLL ans = look(grid, s);
			cout << ans.first << ' ' << ans.second << endl;
		}
	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		if (i != 0) cout << endl;
		SOLVE::main();
	}

	return 0;
}
