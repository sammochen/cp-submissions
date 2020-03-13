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

bool comp(const PLL & a, const PLL & b) {
    return (a.first * b.second) < (b.first * a.second);
}

vector<PLL> get(ll n) {
    vector<PLL> ans;
    REP(b,1,n+1) {
        REP(a,1,b+1) {
            if (__gcd(a,b) == 1) ans.push_back({a,b});
        }
    }
    sort(ans.begin(), ans.end(), comp);
    return ans;
}

void solve() {
    ll n, k;
    while (cin >> n >> k) {
        vector<PLL> arr = get(n);
        cout << arr[k-1].first << "/" << arr[k-1].second << endl;
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}