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
	ll n, m;
	cin >> n >> m;
	VLL A(m);
	REP(i,0,m) {
		cin >> A[i];
	}

	VLL small(n+1), big(n+1), sumbig(n+1);
	ll pairs = 0;
	REP(i,1,m) {
		ll a = A[i], b = A[i-1];
		if (a == b) continue;
		pairs++;
		if (a > b) swap(a,b);
		small[a]++;
		big[b]++;
		sumbig[b] += a - (b-a);
	}

	// first sweep
	VLL ans(n);
	
	VLL active(n+2);
	ll cur = 0;
	REP(i,1,n+1) {
		cur += small[i];
		cur -= big[i-1];

		active[i] = cur;	
		ans[0] += cur - big[i];	
	}

	// secondary sweeps
	REP(i,2,n+1) {
		ll right = small[i] * (i-1);
		ll left = sumbig[i];
		ll others = -(active[i] - small[i] - big[i]);
		ll x = ans[0] + right + left + others;
		ans[i-1] = x;
	}
	
	REP(i,0,n) {
		cout << ans[i] << ' ' ;
	}
	cout << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}