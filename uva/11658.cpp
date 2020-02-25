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

// returns possible if you can sum to x
ll pos(ll x, ll ind, VLL & A, VVLL & dp) {
	if (ind == A.size() && x == 0) return 1;
	else if (ind == A.size()) return 0;
	if (x < 0) return 0;

	if (dp[x][ind] != -1) return dp[x][ind];

	ll ans = pos(x - A[ind], ind+1, A, dp) || pos(x, ind+1, A, dp);
	dp[x][ind] = ans;
	return ans;
}

void solve() {
	ll n, ind;
	while (cin >> n >> ind, n||ind) {
		VLL A;
		ll num;
		REP(i,0,n) {
			ll a, b;
			scanf("%lld.%lld", &a, &b);
			ll x = a * 100 + b;
			if (i == ind-1) num = x;
			else A.push_back(x);
		}

		VVLL dp(10001, VLL(A.size(), -1));

		// find the smallest number that you can make with the other numbers that is larger equal to target
		REP(i,0,10001) {
			if (i + num <= 5000) continue;
			if (pos(i, 0, A, dp)) {
				db ans = num * 100 / (db)(i + num);
				printf("%.2f\n", ans);
				break;
			}
		}



	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}