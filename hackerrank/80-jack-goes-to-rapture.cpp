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

struct edge {
    ll to, w;
};

struct todo {
    ll at, w;
};

bool operator<(const todo & a, const todo & b) {
    return a.w > b.w;
}

ll dijk(ll s, ll t, vector<vector<edge>> & E) {
    VLL d(E.size(), inf);
    d[s] = 0;
    priority_queue<todo> pq;
    pq.push({s,0});

    while (pq.size()) {
        todo at = pq.top();
        pq.pop();

        for (edge to : E[at.at]) {
            ll newd = max(d[at.at], to.w);
            if (newd < d[to.to]) {
                d[to.to] = newd;
                pq.push({to.to, newd});
            }
        }
    }
    return d[t];
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<edge>> E(n);
    REP(i,0,m) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        E[a].push_back({b,w});
        E[b].push_back({a,w});
    }  

    ll ans = dijk(0,n-1,E);
    if (ans == inf) cout << "NO PATH EXISTS" << endl;
    else cout << ans << endl;


}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}