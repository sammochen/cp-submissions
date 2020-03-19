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

void solve() {
	ll n, d, nax = 30005, border = 250;
	cin >> n >> d;
	VLL gems(nax);
	REP(i,0,n) {
		ll x;
		cin >> x;
		gems[x]++;
	}

	ll ans = -inf;
	VVLL dp(nax, VLL(border*2, -inf));
	dp[d][border] = 0;
	// for each one, push up
	REP(i,0,nax) {
		REP(j,0,border*2) {
			if (dp[i][j] == -inf) continue;
			ll dd = j - border + d;

			dp[i][j] += gems[i];

			// push up
			if (i+dd+1 < nax && j+1 < border*2) dp[i+dd+1][j+1] = max(dp[i+dd+1][j+1], dp[i][j]);
			if (i+dd < nax) dp[i+dd][j] = max(dp[i+dd][j], dp[i][j]);
			if (i+dd-1 < nax && j-1 >= 0) dp[i+dd-1][j-1] = max(dp[i+dd-1][j-1], dp[i][j]);

			ans = max(ans, dp[i][j]);
		}
	}

	
	cout << ans << endl;





}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}