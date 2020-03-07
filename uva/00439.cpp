#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
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
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

VLL bfs(ll s) {
	VLL di = {1,2,2,1,-1,-2,-2,-1};
	VLL dj = {2,1,-1,-2,-2,-1,1,2};
	VLL d(64, inf);
	queue<ll> Q;
	Q.push(s);
	d[s] = 0;
	while (Q.size()) {
		ll at = Q.front();
		ll x = at/8;
		ll y = at%8;
		Q.pop();

		REP(i,0,8) {
			ll xx = x + di[i];
			ll yy = y + dj[i];
			if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) continue;
			ll to = xx*8+yy;
			if (d[to] == inf) {
				d[to] = d[at] + 1;
				Q.push(to);
			}
		}
	}
	return d;
}

void solve() {
	VVLL d(64);
	REP(i,0,64) d[i] = bfs(i);
	string s, t;
	while (cin >> s >> t) {
		ll x = (s[0]-'a')*8 + s[1]-'1';
		ll y = (t[0]-'a')*8 + t[1]-'1';
		printf("To get from %s to %s takes %lld knight moves.\n", s.c_str(), t.c_str(), d[x][y]);
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}