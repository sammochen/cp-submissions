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

const ll inf = (ll)1e9 + 7;

namespace maxFlow {
    const ll maxn = 110, maxe = 10010, source = maxn - 1, sink = maxn - 2;
    ll cnt = 0;
    
    struct edge {
        ll from, to, cap;
        
        edge(ll a, ll b, ll c) : from(a), to(b), cap(c) {}
        
        edge() {
            from = to = cap = 0;
        }
    };
    
    vector<ll> g[maxn];
    edge e[maxe];
    
    void clear() {
        cnt = 0;
        REP(i, 0, maxn) g[i].clear();
        REP(i, 0, maxe) e[i] = edge();
    }
    
    void addEdge(ll u, ll v, ll cap) {
        ll cur = cnt;
        e[cur] = edge(u, v, cap);
        g[u].push_back(cur);
        e[cur ^ 1] = edge(v, u, 0);
        g[v].push_back(cur ^ 1);
        cnt += 2;
    }
    
    ll lvl[maxn], cur[maxn];
    
    bool bfs(ll start = source) {
        memset(lvl, -1, sizeof(lvl));
        memset(cur, 0, sizeof(cur));
        lvl[start] = 0;
        queue <ll> q;
        q.push(start);
        
        while (q.size()) {
            ll f = q.front();
            q.pop();
            for (auto curEdge:g[f]) {
                auto &E = e[curEdge];
                if (E.cap) {
                    if (lvl[E.to] == -1) {
                        lvl[E.to] = lvl[f] + 1;
                        q.push(E.to);
                    }
                }
            }
        }
        
        return lvl[sink] != -1;
    }
    
    
    ll dfs(ll curNode, ll curCap) {
        if (!curCap || curNode == sink)return curCap;
        ll ans = 0;
        for (ll &i = cur[curNode]; i < g[curNode].size(); i++) {
            ll curEdge = g[curNode][i];
            if (lvl[e[curEdge].to] > lvl[curNode]) {
                ll delta = dfs(e[curEdge].to, min(e[curEdge].cap, curCap));
                ans += delta;
                curCap -= delta;
                e[curEdge].cap -= delta;
                e[curEdge ^ 1].cap += delta;
                if (!curCap)break;
            }
        }
        return ans;
    }
    
    ll dinic() {
        ll ans = 0;
        while (bfs()) {
            ans += (dfs(source, inf));
        }
        return ans;
    }
}

ll good(PLL & a, PLL & b, ll k) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx*dx + dy*dy <= k*k ? 1 : 0;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<PLL> one, two;
    REP(i,0,n) {
        ll x, y;
        string s;
        cin >> x >> y >> s;
        if (s == "blue") one.push_back({x,y});
        else two.push_back({x,y});
    }

    ll L = 0, R = 3000;
    while (L<R) {
        ll M = (L+R)/2;

        maxFlow::clear();
        REP(i,0,one.size()) {
            REP(j,0,two.size()) {
                PLL a = one[i];
                PLL b = two[j];
                if (good(a,b,M)) {
                    maxFlow::addEdge(i,j+one.size(),1);
                }
            }
        }

        REP(i,0,one.size()) {
            maxFlow::addEdge(maxFlow::source, i, 1);
        }

        REP(j,0,two.size()) {
            maxFlow::addEdge(j+one.size(), maxFlow::sink, 1);
        }

        ll match = maxFlow::dinic();
        if (match >= k) R=M;
        else L=M+1;
    }

    if (L == 3000) printf("Impossible\n");
    else printf("%lld\n", L);
}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}