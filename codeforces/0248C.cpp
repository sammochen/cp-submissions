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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;
const db eps = 1e-12;

void solve() {
	db y1, y2, yw, x, y, r;
	cin >> y1 >> y2 >> yw >> x >> y >> r;

	db newy1 = (yw - r) * 2 - y1;
	db newy2 = (yw - r) * 2 - y2;
	// always best to choose the highest possible place
	db ytarget = newy1 - r;

	// i will make a line towards that
	db a = y - ytarget;
	db b = -(x - 0);
	db c = a*x + b*y;
	
	db hypot = sqrt(pow(x, 2) + pow(ytarget - y, 2));
	db smallhypot = (ytarget - y) / hypot * (ytarget - newy2);
	db ans = sqrt(pow(ytarget - newy2, 2) - pow(smallhypot, 2));
	// if at the y2 goalpost, it is closer, then its bad
	
	if (ans < r) cout << -1 << endl;
	else printf("%.15f\n", (c - b*(yw-r))/ a);
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}