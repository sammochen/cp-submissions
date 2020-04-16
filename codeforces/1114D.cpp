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
const ll nax = 5005;

VLL B;
ll dp[nax][nax];
// function for longest common subsequence - i goes down, j goes up
ll cost(ll i, ll j) {
	if (i <= -1) return B.size() - j;
	if (j >= (ll)B.size()) return i + 1;
	if (dp[i][j] != -1) return dp[i][j];

	ll ans = inf;
	if (B[i] == B[j]) ans = min(ans, cost(i-1, j+1) + 1);
	ans = min(ans, cost(i-1, j) + 1);
	ans = min(ans, cost(i, j+1) + 1);

	dp[i][j] = ans;
	return ans;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	ll n;
	cin >> n;
	VLL A(n);
	REP(i,0,n) cin >> A[i];

	B = {A[0]};
	REP(i,1,n) {
		if (A[i] != A[i-1]) B.push_back(A[i]);
	}
	
	ll best = inf;
	REP(i,0,(ll)B.size()) {
		best = min(best, cost(i-1,i+1));
	}
	cout << best << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}