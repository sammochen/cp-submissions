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
VLL bfs(VVLL & E, VVLL & W, ll s) {
    VLL D(E.size(), inf);
    queue<ll> Q;
    D[s] = 0;
    Q.push(s);
    while (Q.size()) {
        ll at = Q.front();
        Q.pop();
        for (ll to : E[at]) {
            if (W[at][to] <= 0) continue;
            if (D[to] != inf) continue;
            D[to] = D[at] + 1;
            Q.push(to); 
        }
    }
    return D;
}

// returns the maxflow possible from at to t
ll dfs(VVLL & E, VVLL & W, VLL & D, ll at, ll t, ll f) {
    if (at == t) {
        return f;
    }

    for (ll to : E[at]) {
        if (W[at][to] > 0 && D[to] == D[at] + 1) {
            ll flow = dfs(E, W, D, to, t, min(f, W[at][to]));
            if (flow > 0) {
                W[at][to] -= flow;
                W[to][at] += flow;
                return flow;
            }
        }
    }
    return 0;
}

// returns the max flow
ll dinic(VVLL E, VVLL W, ll s, ll t) {
    ll mf = 0;
    while (1) {
        // do bfs
        VLL D = bfs(E, W, s);
        if (D[t] == inf) return mf;

        // do dfs 
        while (1) {
            ll f = dfs(E,W,D,s,t,inf);
            mf += f;
            if (f == 0) break;
        }
    }
    return mf;
}

void addedge(VVLL & E, VVLL & W, ll a, ll b, ll w) {
    E[a].push_back(b);
    E[b].push_back(a);
    W[a][b] = w;
}

ll side(ll x1, ll y1, ll x2, ll y2, ll a, ll b) {
    ll dx1 = x1-x2;
    ll dy1 = y1-y2;
    ll dx2 = x1-a;
    ll dy2 = y1-b;
    if (dx2*dy1 == dx1*dy2) return 0;
    if (dx2*dy1 > dx1*dy2) return 1;
    if (dx2*dy1 < dx1*dy2) return 2;
    exit(1);
}

void solve() {
    ll n;
    ll test = 1;
    while (cin >> n, n) {
        VVLL A(n, VLL(3));
        REP(i,0,n) {
            REP(j,0,3) {
                cin >> A[i][j];
            }
        }

        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;

        VVLL one;
        VVLL two;
        REP(i,0,n) {
            if (A[i][2] == 0) continue;
            ll s = side(A[a][0], A[a][1], A[b][0], A[b][1], A[i][0], A[i][1]);
           
            if (s == 1) one.push_back(A[i]);
            if (s == 2) two.push_back(A[i]);
        }

        if (one.size() > two.size()) swap(one,two);

        VVLL E(n+5);
        VVLL W(n+5, VLL(n+5));

        ll s = n+3, t = n+4;
        REP(i,0,one.size()) {
            REP(j,0,two.size()) {
                ll dx = one[i][0] - two[j][0];
                ll dy = one[i][1] - two[j][1];
                if (dx*dx + dy*dy <= c*c) {
                    if (one[i][2] > two[j][2]) {
                        addedge(E, W, i, j+one.size(), 1);
                    }
                }
            }
        }

        REP(i,0,one.size()) {
            addedge(E, W, s, i, 1);
        }
        REP(j,0,two.size()) {
            addedge(E, W, j+one.size(), t, 1);
        }

        ll ans = dinic(E, W, s, t);
        printf("Case %lld: %lld\n", test++, ans);
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}