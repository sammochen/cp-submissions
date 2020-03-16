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

// find the value just smaller than x
db bs(vector<db> & f, db x) {
    ll L = 0, R = f.size() - 1;
    while (L < R) {
        ll M = (L+R)/2;
        if (ceil(f[M]) <= x) L = M+1;
        else R = M;
    }
    return L-1;
}
void solve() {
    ll n, nax = 300000;
    vector<db> f(nax);
    f[0] = 0;
    REP(i,1,nax) {
        f[i] = f[i-1] + log2(i);
    }

    while (cin >> n, n) {
        n -= 1960;
        // every 10 years, it doubles
        db x = pow(2,n/10) * 4; // 2^x is the chip size
        cout << bs(f, x) << endl;
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}