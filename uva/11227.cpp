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

ll test = 1;
void solve() {
    ll n;
    cin >> n;
    map<PLL,ll> f;
    vector<PLL> points;

    REP(i,0,n) {
        db a, b;
        cin >> a >> b;
        ll x = a*100, y = b*100;
       
        if (f[{x,y}]) continue;
        points.push_back({x,y});
        f[{x,y}] = 1;
    }
    
    // for every pair of points, make a line and see how many points are on the line
    n = points.size();
    if (n == 1) {
        printf("Data set #%lld contains a single gnu.\n", test++);
        return;
    }
    ll ans = 0;
    REP(i,0,n) {
        REP(j,i+1,n) {
            // establish a line
            ll cnt = 0;
            REP(k,0,n) {
                // see how many points lie on that line
                ll dx1 = points[k].first - points[i].first;
                ll dx2 = points[k].first - points[j].first;
                ll dy1 = points[k].second - points[i].second;
                ll dy2 = points[k].second - points[j].second;
                if (dx1 * dy2 == dx2 * dy1) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    printf("Data set #%lld contains %lld gnus, out of which a maximum of %lld are aligned.\n", test++, n, ans);
}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}