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

PLL pos(ll a) {
    ll row = sqrt(a);
    ll col = a - ((row+1)*(row+1) + row*row)/2;
    return {row, col};
}
pair<db,db> xy(ll a) {
    PLL p = pos(a);
    db y = sqrt(3)/2.0 * p.first;
    y += (p.second+p.first) % 2 ? sqrt(3)/6 : sqrt(3)/3;
    db x = p.second * 0.5;
    return {x,y};
}

db dist(ll a, ll b) {
    pair<db,db> apos = xy(a), bpos = xy(b);
    return sqrt(pow(apos.first-bpos.first,2) + pow(apos.second-bpos.second,2));
}
void solve() {
    ll a, b;
    while (cin >> a >> b) {
        printf("%.3f\n", dist(a,b));
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}