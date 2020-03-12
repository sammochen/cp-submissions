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

ll nax = 400;
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

// count number of occurences of k in fac
// eg if amount(7, 2) = 4 (2, 4, 6) -> 4
ll amount(ll fac, ll k) {
    ll power = k;
    ll ans = 0;
    while (power <= fac) {
        ans += fac/power;
        power *= k;
    }
    return ans;
}

ll fit(ll fac, ll x) {
    ll og = x;
    // prime factorise, and for each prime factor f with occurence k, check if p*f <= x
    vector<PLL> f;
    REP(i,0,P.size()) {
        if (P[i] * P[i] > x) break;
        while (x % P[i] == 0) {
            if (f.size() == 0 || f[f.size() - 1].first != P[i]) {
                f.push_back({P[i], 1});
            } else {
                f[f.size() - 1].second++;
            }
            x /= P[i];
        }
    }
    if (x > 1) f.push_back({x, 1});

    REP(i,0,f.size()) {
        if (f[i].second > amount(fac, f[i].first)) return 0;
    }
    return 1;
}

void solve() {
    ll n, m;
    while (cin >> n >> m) {
        if (fit(n, m)) {
            printf("%lld divides %lld!\n", m, n);
        } else {
            printf("%lld does not divide %lld!\n", m, n);
        }
    }

}

signed main() {
	init();
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}