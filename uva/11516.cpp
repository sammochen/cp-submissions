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


ll many(VLL & houses, db dist) {
    db prev = -inf;
    ll ans = 0;
    REP(i,0,houses.size()) {
        if (abs(houses[i] - prev) <= dist) continue;
        prev = houses[i] + dist;
        ans++;
    }
    return ans;
}

void solve() {
    ll k, n;
    cin >> k >> n;
    VLL houses(n);
    REP(i,0,n) cin >> houses[i];
    sort(houses.begin(), houses.end());

    // if i wanted it in one meter
    db L = 0, R = 1000005;
    while (L +1e-6 < R) {
        db M = (L+R)/2;
        ll cnt = many(houses, M);
        if (cnt <= k) R=M;
        else L = M+1e-6;
    }

    printf("%.1f\n", L);

}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}