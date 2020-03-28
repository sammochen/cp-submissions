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

ll dfs1(ll at, ll prev, VVLL & E, map<PLL,ll> & good) {
    ll ans = 0;
    for (ll to : E[at]) {
        if (to == prev) continue;
        if (good[{at,to}]) ans++;

        ans += dfs1(to, at, E, good);
    }
    return ans;
}

ll dfs2(ll at, ll prev, VVLL & E, map<PLL,ll> & good, ll cur, ll & k) {
    ll ans = 0;
    if (cur >= k) ans++;
    for (ll to : E[at]) {
        if (to == prev) continue;
        ll nextcur = cur + (good[{to,at}] - good[{at,to}]);
        ans += dfs2(to, at, E, good, nextcur, k);
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    VVLL E(n);
    REP(i,0,n-1) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    ll q, k;
    cin >> q >> k;
    map<PLL,ll> freq;
    REP(i,0,q) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        freq[{a,b}] = 1;
    }

    // do a dfs to get how many are good from root
    ll root = 0;
    
    ll good = dfs1(root, -1, E, freq);

    // and then i will do dfs2 to count how many good ones
    ll top = dfs2(root, -1, E, freq, good, k);
    ll bottom = n;

    ll g = __gcd(top, bottom);
    printf("%lld/%lld\n", top/g, bottom/g);
}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}