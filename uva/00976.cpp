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

ll get(ll ind, ll bridges, VLL & cost, ll & gap, VVLL & dp) {
	// take or dont take
	if (bridges == 0) return 0;
	if (ind >= cost.size()) return inf;

	if (dp[ind][bridges] != -1) return dp[ind][bridges];

	ll ans = get(ind + 1, bridges, cost, gap, dp); // dont take
	ans = min(ans, cost[ind] + get(ind + gap + 1, bridges - 1, cost, gap, dp));

	dp[ind][bridges] = ans;
	return ans;
}

void dfs(ll i, ll j, ll color, VVLL & grid, vector<string> & og) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
	if (grid[i][j]) return;
	if (og[i][j] == '.') return;

	grid[i][j] = color;

	VLL di = {0,0,1,-1};
	VLL dj = {1,-1,0,0};
	REP(x,0,4) {
		dfs(i+di[x], j+dj[x], color, grid, og);
	}
	
}

void solve() {
	ll n, m;
	while (cin >> n >> m) {
		ll bridges, gap;
		cin >> bridges >> gap;

		vector<string> A(n);
		REP(i,0,n) cin >> A[i];

		VVLL grid(n, VLL(m));
		dfs(0,0,1,grid,A);
		dfs(grid.size()-1,0,2,grid,A);

		VLL lowestone(m, -inf), highesttwo(m, inf);
		REP(i,0,n) {
			REP(j,0,m) {
				if (grid[i][j] == 1) lowestone[j] = max(lowestone[j], i);
				if (grid[i][j] == 2) highesttwo[j] = min(highesttwo[j], i);
			}
		}

		VLL cost(m);
		REP(i,0,m) cost[i] = highesttwo[i] - lowestone[i] - 1;

		VVLL dp(m, VLL(bridges+1, -1));
		ll ans = get(0, bridges, cost, gap, dp);
		cout << ans << endl;
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}