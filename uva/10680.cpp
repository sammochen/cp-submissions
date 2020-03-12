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

map<ll,ll> factorise(ll n) {
    map<ll,ll> freq;
    REP(i,0,P.size()) {
        if (P[i] * P[i] > n) break;
        while (n % P[i] == 0) {
            freq[P[i]]++;
            n /= P[i];
        }
    }
    if (n != 1) freq[n]++;
    return freq;
}

void solve() {
    ll n = 1000005;
    VLL ans(n);
    debug(P.size());    
    map<ll,ll> m;
    ll cur = 1;
    REP(i,1,n) {
        map<ll,ll> freq = factorise(i);
        for (auto x : freq) {
            if (m[x.first] < x.second) {
                cur *= pow(x.first, x.second - m[x.first]);
                m[x.first] = x.second;

                while (cur%10 == 0) cur/=10;
                cur %= 1000000000;
            }
        }
        ans[i] = cur%10;
    }

    ll x;
    while (cin >> x, x) {
        cout << ans[x] << endl;
    }


}

signed main() {
	init();
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}