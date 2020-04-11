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

ll nax = 335;
VLL p(nax*nax, 1);
VLL P;

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}

		P.push_back(x);
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}
}

map<ll,ll> pf(ll x) {
    map<ll,ll> f;
    REP(i,0,P.size()) {
        if (P[i] * P[i] > x) break;
        while (x % P[i] == 0) {
            f[P[i]]++;
            x /= P[i];
        }
    }
    if (x > 1) f[x]++;
    return f;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	VLL A(n);
	map<map<ll,ll>,ll> count;
	ll ans = 0;
	REP(i,0,n) {
		cin >> A[i];
		
		map<ll,ll> id, other;
		for (auto p : pf(A[i])) {
			ll v = p.second % k;
			if (v) id[p.first] = v;
			ll w = (k - v) % k;
			if (w) other[p.first] = w;
		}

		ans += count[other];
		count[id]++;
	}
	cout << ans << endl;
}

signed main() {
	init();
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}