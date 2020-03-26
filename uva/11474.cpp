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
const ll nax = 200;
ll p[nax];

ll getp(ll x) {
    if (p[x] == x) return x;
    p[x] = getp(p[x]);
    return p[x];
}

ll same(ll a, ll b) {
    return getp(a) == getp(b);
}

void merge(ll a, ll b) {
    if (same(a,b)) return;
    p[getp(a)] = getp(b);
}

ll good(PLL a, PLL b, ll k) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    if (dx*dx + dy*dy <= (k*k)) return 1;
    return 0;
}

void solve() {
    REP(i,0,nax) p[i] = i;

    // doctor is n

    ll n, m, k, d;
    cin >> n >> m >> k >> d; // k is threshold for tree-tree, d is threshold for tree-doctor
    vector<PLL> doctors(m);
    vector<vector<PLL>> trees(n);
    REP(i,0,m) {
        cin >> doctors[i].first >>  doctors[i].second;
    }

    REP(i,0,n) {
        ll b;
        cin >> b;
        trees[i].resize(b);
        REP(j,0,b) cin >> trees[i][j].first >> trees[i][j].second;
    }

    // pair between trees
    REP(i,0,n) {
        REP(j,i+1,n) {
            if (same(i,j)) continue;

            for (PLL a : trees[i]) {
                if (same(i,j)) break;
                for (PLL b : trees[j]) {
                    if (good(a,b,k)) {
                        merge(i,j);
                        break;
                    }
                }
            }
        }
    }

    // link to doctors
    REP(i,0,n) {
        if (same(i,n)) continue;
        for (PLL a : trees[i]) {
            if (same(i,n)) break;
            for (PLL b : doctors) {
                if (good(a,b,d)) {
                    merge(i,n);
                    break;
                }
            }
        }
    }

    if (same(0,n)) printf("Tree can be saved :)\n");
    else printf("Tree can't be saved :(\n");

}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}