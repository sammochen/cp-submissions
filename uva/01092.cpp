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

void solve() {
    ll test = 1;
    ll n, m, k;
    // i read the inputs the wrong way round
    while (cin >> n >> m >> k, n||m||k) {
        set<ll> x, y;
        map<ll,vector<PLL>> walls;
        x.insert(0);
        x.insert(m);
        y.insert(0);
        y.insert(n);
        REP(i,0,k) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            x.insert(a);
            x.insert(c+1);
            y.insert(b);
            y.insert(b+1);
            walls[b].push_back({a,c});
        }

        VLL X, Y;
        for (ll xx : x) X.push_back(xx);
        for (ll yy : y) Y.push_back(yy);

        ll N = Y.size(), M = X.size();
        VVLL iswall(N, VLL(M));
        VVLL dp(N, VLL(M));

        REP(i,0,N) {
            sort(walls[Y[i]].begin(), walls[Y[i]].end());
            ll wallit = 0;
            ll Xit = 0;
            while (wallit < walls[Y[i]].size()) {
                // move the xit closer
                while (X[Xit] < walls[Y[i]][wallit].first) {
                    Xit++;
                }
                while (X[Xit] <= walls[Y[i]][wallit].second) {
                    iswall[i][Xit] = 1;
                    Xit++;
                }
                wallit++;
            }
        }

        ll ans = 0;
        dp[N-2][M-2] = 1;
        RREP(i,N-2,0) {
            RREP(j,M-2,0) {
                if (iswall[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] |= dp[i+1][j];
                dp[i][j] |= dp[i][j+1];
            }
        }
              
        REP(i,0,N-1) {
            REP(j,0,M-1) {
                if (!dp[i][j] && !iswall[i][j]) {
                    ans += (Y[i+1]-Y[i]) * (X[j+1] - X[j]);
                }
            }
        }
    

        printf("Case %lld: %lld\n", test++, ans);
    }
    
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}