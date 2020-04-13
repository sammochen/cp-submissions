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

struct sammo {
	bool operator() (const VLL & a, const VLL & b) {
		return a.size() < b.size();
	}
};

void solve() {
	ll n, k;
	cin >> n >> k;
	VLL A(n);
	REP(i,0,n) cin >> A[i];

	map<ll,VLL> ind;
	set<ll> nums;
	REP(i,0,n) {
		ind[A[i]].push_back(i);
		nums.insert(A[i]);
	}

	VLL ans(n);
	ll color = 1;
	for (ll x : nums) {
		if (ind[x].size() > k) {
			cout << "NO" << endl;
			return;
		}
		for (ll i : ind[x]) {
			ans[i] = color;
			color++;
			if (color > k) color = 1;
		}
	}

	cout << "YES" << endl;
	for (ll x : ans) cout << x << ' ';
	cout << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}