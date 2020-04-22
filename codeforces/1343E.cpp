#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

VLL bfs(VVLL & E, ll s) {
	VLL d(E.size(), inf);
	queue<ll> Q;
	Q.push(s);
	d[s] = 0;
	while (Q.size()) {
		ll at = Q.front();
		Q.pop();

		for (ll to : E[at]) {
			if (d[to] == inf) {
				d[to] = d[at] + 1;
				Q.push(to);
			}
		}
	}
	return d;
}

void solve() {
	ll n, m, a, b, c;
	in(n,m,a,b,c);
	a--;b--;c--;

	VLL cost(m);
	in(cost);
	sort(all(cost));

	VLL pre(m+1);
	REP(i,0,m) pre[i+1] = pre[i] + cost[i];

	
	VVLL E(n);
	REP(i,0,m) {
		ll x, y;
		in(x,y);
		x--;y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}

	VLL froma = bfs(E, a);
	VLL fromb = bfs(E, b);
	VLL fromc = bfs(E, c);

	ll ans = inf;
	REP(i,0,n) {
		ll total = froma[i] + fromb[i] + fromc[i];
		if (total > m) continue;
		
		ll cur = pre[total] + pre[fromb[i]];
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	in(t);
	REP(i,0,t) solve();
	return 0;
}