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

ll dist(ll a, ll b, ll c, ll d) {
	return (a-c)*(a-c) + (b-d)*(b-d);
}

ll split(string s) {
	string t;
	REP(i,0,s.length()) {
		if (s[i] != '.') t.push_back(s[i]);
	}
	return stoll(t);
}

void solve() {
	ll n, a;
	while (cin >> n >> a, n||a) {
		ll cnt = 0;
		REP(i,0,n) {
			string s, t;
			cin >> s >> t;

			ll x = split(s);
			ll y = split(t);

			ll A = a * 10000000;

			ll d = A*A;

			ll good = 1;
			if (dist(x,y,0,0) > d) good = 0;
			if (dist(x,y,0,A) > d) good = 0;
			if (dist(x,y,A,0) > d) good = 0;
			if (dist(x,y,A,A) > d) good = 0;

			cnt += good;
		}

		printf("%.5f\n", (db)cnt*a*a/n);
		
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}