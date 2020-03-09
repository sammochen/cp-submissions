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

void solve() {
	db a, b, c;
	while (cin >> a >> b >> c) {
		db bigr = a*b*c / sqrt((a+b+c)*(b+c-a)*(a+b-c)*(a+c-b));
		db s = (a+b+c)/2;
		db smallr = sqrt(s*(s-a)*(s-b)*(s-c))/s;
		db pi = 2*acos(0);
		db trianglearea = sqrt(s*(s-a)*(s-b)*(s-c));
		db sunflower = bigr*bigr*pi - trianglearea;
		db violet = trianglearea - smallr*smallr*pi;
		db rose = smallr*smallr*pi;
		printf("%.4f %.4f %.4f\n", sunflower,violet,rose);
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}