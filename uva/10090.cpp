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

// Function for extended Euclidean Algorithm  
ll gcde(ll a, ll b, ll & x, ll & y) {
    // Base Case  
    if (a == 0) {  
        x = 0;
        y = 1;  
        return b;  
    }  
  
    ll x1, y1; // To store results of recursive call  
    ll gcd = gcde(b%a, a, x1, y1);  
  
    // Update x and y using results of  
    // recursive call  
    x = y1 - (b/a) * x1;  
    y = x1;  
  
    return gcd;  
}  

ll mod(ll x, ll m) {
    x %= m;
    x += m;
    x %= m;
    return x;
}

void solve() {
    ll n, a, b, c, d;
    while (cin >> n, n) {
        cin >> a >> b >> c >> d;
        ll x, y;
        ll g = gcde(b, d, x, y);
        if (n % g) {
            cout << "failed" << endl;
            continue;
        }
        x *= n/g;
        y *= n/g;

        
        ll x1 = mod(x, d/g);
        ll y1 = (n - x1*b) / d;
        if (y1 < 0) {
            cout << "failed" << endl;
            continue;
        }

        ll y2 = y = mod(y, b/g);
        ll x2 = x = (n - y2*d) / b;
       
        if (x1 * a + y1 * c < x2 * a + y2 * c) {
            cout << x1 << ' ' << y1 << endl;
        } else {
            cout << x2 << ' ' << y2 << endl;
        }
    }
    
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}