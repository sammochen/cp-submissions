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

ll bs(ll L, ll R, ll target, VLL & A) {
	if (A[R] < target) return -1;
	while (L<R) {
		ll M = (L+R)/2;
		if (A[M] >= target) R = M;
		else L = M+1;
	}
	return L;
}
void solve() {
	ll n;
	cin >> n;
	VLL A(n), B(n);
	REP(i,0,n) cin >> A[i];
	REP(i,0,n) cin >> B[i];

	VLL diffs(n);
	REP(i,0,n) diffs[i] = A[i] - B[i];

	sort(diffs.begin(), diffs.end());

	ll ans = 0;
	REP(i,1,n) {
		ll ind = bs(0, i-1, -diffs[i]+1, diffs);
		if (ind == -1) continue;
		ans += i - ind;
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}