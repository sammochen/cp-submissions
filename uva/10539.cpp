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
const ll nax = 1e3+5;
VLL p(nax*nax, 1);
VLL almost;

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax; x++) {
		if (p[x] == 0) {
			continue;
		}
		
		for (ll f = 2; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}

	REP(i,0,nax*nax) {
		if (p[i]) {
			ll v = i * i;
			while (v <= (ll)1e12 + 50) {
				almost.push_back(v);
				v *= i;
			}
		}
	}
	sort(almost.begin(), almost.end());
	almost.push_back(1e12 + 10); // add one that is higher than all
}

ll high(ll x) {
	ll L = 0, R = almost.size() - 1;
	while (L < R) {
		ll M = (L+R)/2;
		if (almost[M] >= x) R = M;
		else L = M+1;
	}
	return L;
}

void solve() {
	ll a, b;
	cin >> a >> b;

	ll ans = high(b+1) - high(a);
	cout << ans << endl;

}

signed main() {
	init();
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}