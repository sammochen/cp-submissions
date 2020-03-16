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

struct fraction {
    ll a, b;
};

void simplify(fraction & f) {
    ll g = __gcd(f.a, f.b);
    f.a /= g;
    f.b /= g;
}

fraction operator+(fraction & a, fraction & b) {
    ll bot = a.b * b.b;
    ll top = a.a * b.b + a.b * b.a;
    fraction f = {top,bot};
    simplify(f);
    return f;
}

void solve() {
    ll nax = 100005;
    vector<fraction> ans(nax);
    ans[1] = {0,1};
    REP(i,2,nax) {
        fraction add = {(i)*(i-1)/2, i};
        ans[i] = ans[i-1] + add;
    }

    ll q;
    cin >> q;
    REP(i,0,q) {
        ll x;
        cin >> x;
        debug(ans[x].a, ans[x].b);
        
        if (ans[x].b == 1) printf("Case %lld: %lld\n", i+1, ans[x].a);
        else printf("Case %lld: %lld/%lld\n", i+1, ans[x].a, ans[x].b);
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}