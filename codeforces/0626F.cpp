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
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;
ll mod = 1e9+7;

VLL A;
int dp[202][202][1002];

// how many ways you can partition some group
ll get(ll cur, ll open, ll cost) {
	if (cur == -1 && open == 0 && cost == 0) return 1;
	if (cur == -1) return 0;
	if (cost < 0) return 0;
	if (open < 0) return 0;
	if (open-1 > cur) return 0;

	if (dp[cur][open][cost] != -1) return dp[cur][open][cost];

	ll ans = 0;
	ll newcost = open == 0 ? cost : cost - open * (A[cur+1] - A[cur]);
	// open
	ans += get(cur-1, open+1, newcost);
	// its own group
	ans += get(cur-1, open, newcost);
	// insert into some group, and not close it
	ans += get(cur-1, open, newcost) * open;
	// insert into some group, and close it
	ans += get(cur-1, open-1, newcost) * open;

	ans %= mod;

	dp[cur][open][cost] = ans;
	return ans;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	A.resize(n);

	memset(dp, -1, sizeof(dp));

	REP(i,0,n) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	ll ans = 0;
	REP(i,0,k+1) {
		ans += get(n-1,0,i);
	}
	ans %= mod;
	cout << ans << endl;

	
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}