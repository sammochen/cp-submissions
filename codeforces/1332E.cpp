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
const ll mod = 998244353;

ll POW(ll a, ll b) {
    if (b == 0) return 1;	
	ll h = POW(a, b/2);
    ll ans = h*h%mod;
    if (b%2) ans *= a;
	ans %= mod;
	return ans;
}

ll divide(ll a, ll b) {
    return a % mod * POW(b, mod-2) % mod;
}

void solve() {
    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    ll choices = R-L+1;
    
    if ((n*m) % 2) {
        ll ans = POW(choices, n*m);
        cout << ans%mod << endl;
    } else if (choices % 2 == 0) {
        ll ans = divide(POW(choices, n*m), 2);
        cout << ans%mod << endl;
    } else {
        ll ans = divide(POW(choices, n*m) + 1, 2);
        cout << ans%mod << endl;
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}