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

ll dp[1005][105];

ll n, d, k;
VLL A;

ll get(ll ind, ll energy) {
	if (ind >= A.size()) return 0;
	if (dp[ind][energy] != -1) return dp[ind][energy];

	ll ans = 0;
	ans = max(ans, get(ind+1, energy));
	REP(i,1,k+1) {
		if (ind + 2*i >= A.size()) break;
		if (i > energy) break;

		ans = max(ans, get(ind + 2*i, energy - i) + (i*A[ind + 2*i]));
	}

	dp[ind][energy] = ans;
	return ans;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> d >> k;
	A.resize(n+1);
	REP(i,1,n+1) cin >> A[i];

	ll ans = get(0, d);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}