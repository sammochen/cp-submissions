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


void bad() {
	cout << -1 << endl;
	exit(0);
}

void solve() {
	ll n, m;
	cin >> n >> m;
	VVLL E(n);
	REP(i,0,m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	// first, put 0 in one
	VLL ans(n);

	ll one = 0;
	ans[one] = 1;

	// any vertices that dont come up in 0, has to also be a 1
	VLL vis1(n);
	for (ll to : E[one]) {
		vis1[to] = 1;
	}
	REP(i,0,n) {
		if (!vis1[i]) ans[i] = 1;
	}

	// repeat - choose the first number that is non 0
	ll two = -1;
	REP(i,0,n) {
		if (ans[i] == 0) {
			two = i;
			break;
		}
	}

	if (two == -1) bad();

	VLL vis2(n);
	for (ll to : E[two]) {
		vis2[to] = 1;
	}
	REP(i,0,n) {
		if (!vis2[i]) {
			if (ans[i]) bad();
			ans[i] = 2;
		}
	}

	VLL count(3);
	REP(i,0,n) {
		if (ans[i] == 0) ans[i] = 3;
		count[ans[i] - 1]++;
	}

	if (count[0] == 0 || count[1] == 0 || count[2] == 0) bad();

	// now i check the edges to see if this solution fits
	REP(i,0,n) {
		VLL freq(3);
		for (ll to : E[i]) {
			freq[ans[to] - 1]++;
		}
		REP(j,0,3) {
			if (j == ans[i] - 1) {
				if (freq[j] != 0) bad();
			} else {
				if (freq[j] != count[j]) bad();
			}
		}
	}
	REP(i,0,n) cout << ans[i] << ' ';
	cout << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}