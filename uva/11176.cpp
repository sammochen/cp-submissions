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
    ll n;
    db p;
    while (cin >> n >> p, n) {

        vector<vector<db>> dp(n+5, vector<db>(n+5));
        VVLL done(n+5, VLL(n+5));
        dp[0][0] = 1;
        done[0][0] = 1;
        REP(i,0,n) {
            REP(j,0,n+1) {
                if (!done[i][j]) break;
                // see how dp[i][j] affects the ones above it

                // add some streak and space
                REP(k,0,n+5) {
                    if (i+k+1 >= n+5) break;
                    dp[i+k+1][max(k,j)] += dp[i][j] * pow(p,k) * (1-p);
                    done[i+k+1][max(k,j)] = 1;
                }

                // add some streak to the end
                dp[n][max(n-i,j)] += dp[i][j] * pow(p, n-i);
                done[n][max(n-i,j)] = 1;
            }
        }

        db ans = 0;
        REP(i,1,n+1) {
            ans += i * dp[n][i];
        }
        printf("%.10f\n", ans);
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}