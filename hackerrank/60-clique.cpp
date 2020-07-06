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

// turan's theorum
// https://mathworld.wolfram.com/TuransTheorem.html
// this gives the max edges that can occur with at most k cliques
ll t(ll n, ll k) {
    return ((k-1)*n*n) / (2*k);
}

int get_calc(int m, int n) {
    int g1 = n % m;
    int g2 = m - g1;
    int sz1 = n / m + 1;
    int sz2 = n / m;

    return g1 * sz1 * g2 * sz2 + g1 * (g1 - 1) * sz1 * sz1 / 2 + g2 * (g2 - 1) * sz2 * sz2 / 2;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll L = 1, R = n+1;
    while (L<R) {
        ll M = (L+R)/2;
        //if (t(n,M) < m) L = M+1;
        if (get_calc(M,n) < m) L = M+1;
        else R = M;
    }
    
    cout << L << endl;
    
}

signed main() {
    ll t = 1;
    cin >> t;
    REP(i,0,t) solve();
    return 0;
}
