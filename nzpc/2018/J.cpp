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

ll dp[505][505];

ll get(ll i, ll j, string & s, string & t) {
	if (i == s.length()) return t.length() - j;
	if (j == t.length()) return s.length() - i;
	if (dp[i][j] != -1) return dp[i][j];

	ll ans = inf;
	if (s[i] == t[j]) ans = min(ans, get(i+1, j+1, s, t));
	ans = min(ans, get(i+1, j, s, t) + 1);
	ans = min(ans, get(i+1, j+1, s, t) + 1);
	ans = min(ans, get(i, j+1, s, t) + 1);

	dp[i][j] = ans;
	return ans;
}

ll edit(string & s, string & t) {
	mst(dp, -1);
	return get(0,0,s,t);
}

string line() {
	string s;
	getline(cin, s);
	return s;
}

void solve() {
	char c = line()[0];
	string s = line();
	string t = line();

	ll a = edit(s,t);
	REP(i,0,t.length()) {
		if (t[i] == c) t[i] = '@';
	}
	ll b = edit(s,t);
	printf("Differences %lld and %lld\n", a, b);
}

signed main() {
	ll t = 1;
	t = stoll(line());
	REP(i,0,t) solve();
	return 0;
}