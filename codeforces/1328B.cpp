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

VLL T;

void solve() {
	ll n, k;
	cin >> n >> k;
	k--;

	ll l = 0, r = T.size() - 1;
	while (l < r) {
		ll m = (l+r)/2;
		if (T[m] <= k) {
			l = m+1;
		} else {
			r = m;
		}
	}
	l--;

	ll rem = k - T[l];
	
	string ans = string(n, 'a');
	ans[n-l-2] = 'b';
	ans[n-rem-1] = 'b';
	cout << ans << endl;


	
}

signed main() {
	REP(i,0,100000) T.push_back(i*(i+1)/2);
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}