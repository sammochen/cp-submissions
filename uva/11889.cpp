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

ll nax = 1005;
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

ll f(ll a, ll c) {
    if (c % a) return -1;
    
    // prime factorise both
    ll ans = 1;
    map<ll,ll> af = pf(a);
    map<ll,ll> cf = pf(c);
    for (PLL p : cf) {
        if (af[p.first] != cf[p.first]) {
            ans *= pow(p.first, cf[p.first]);
        }
    }
    return ans;
}

void solve() {
    ll a, c;
    cin >> a >> c;
    ll ans = f(a,c);
    if (ans == -1) cout << "NO SOLUTION" << endl;
    else cout << ans << endl;

}

signed main() {
	init();
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}