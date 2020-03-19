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
ll mod = 1e9+7;

ll n, k;
ll dp[2005][2005];
ll A[2005];

ll get(ll cur, ll open) {
	// i can either do nothing, open, close, open and close
	if (cur == -1 && open == 0) return 1;
	if (cur == -1) return 0;
	if (dp[cur][open] != -1) return dp[cur][open];

	ll ans = 0;
	// do nothing - cur needs to be good
	if (A[cur] + open == k) ans += get(cur-1, open);
	// close only - there needs to be at least one open
	if (open > 0 && A[cur] + open == k) ans += get(cur-1, open-1) * open;
	// open only
	if (A[cur] + open + 1 == k) ans += get(cur-1, open+1);
	// open and close
	if (A[cur] + open + 1 == k) ans += get(cur-1, open);
	// close and open
	if (open > 0 && A[cur] + open + 1 == k) ans += get(cur-1, open) * open;

	ans %= mod;
	dp[cur][open] = ans;
	return ans;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	REP(i,0,n) cin >> A[i];

	ll ans = get(n-1,0);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}