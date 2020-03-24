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

ll n, h, l, r;
ll A[2005];
ll dp[2005][2005];

ll good(ll x) {
	x %= h;
	if (x >= l && x <= r) return 1;
	return 0;
}

ll get(ll time, ll ind) {
	time %= h;
	if (ind == n) return 0;
	if (dp[time][ind] != -1) return dp[time][ind];
	

	ll ans = get(time+A[ind], ind+1) + good(time+A[ind]);
	ans = max(ans, get(time+A[ind]-1, ind+1) + good(time+A[ind]-1));

	dp[time][ind] = ans;
	return ans;
	
}
void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> h >> l >> r;
	REP(i,0,n) cin >> A[i];

	ll ans = get(0,0);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}