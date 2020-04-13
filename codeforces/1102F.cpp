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

ll n, m;
ll dp[20][20][(1<<16) + 5];

ll get(ll start, ll end, ll mask, VVLL & cost, VVLL & cost2) {
	if (dp[start][end][mask] != -1) return dp[start][end][mask];
	
	ll best = -inf;
	REP(i,0,n) {
		if (i == end) {
			if ((1 << i) == mask) { // last one
				dp[start][end][mask] = cost2[start][i];
				return cost2[start][i];
			}
		} else if ((1 << i) & mask) {
			ll cur = get(i, end, mask & (~(1 << i)), cost, cost2);
			cur = min(cur, cost[start][i]);
			best = max(best, cur);
		}
	}
	dp[start][end][mask] = best;
	return best;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	VVLL A(n, VLL(m));
	REP(i,0,n) REP(j,0,m) cin >> A[i][j];

	VVLL cost(n, VLL(n, inf)); // cost to go from i to j
	VVLL cost2(n, VLL(n, inf)); // weird cost;

	REP(i,0,n) {
		REP(j,0,n) {
			REP(k,0,m) {
				cost[i][j] = min(cost[i][j], abs(A[i][k] - A[j][k]));
				if (k < m - 1) cost2[i][j] = min(cost2[i][j], abs(A[i][k] - A[j][k+1]));
			}
		}
	}

	ll best = -inf;
	REP(i,0,n) {
		best = max(best, get(i, i, (1<<n)-1, cost, cost2));
	}
	cout << best << endl;



}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}