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

ll nax = 1005;
VLL p(nax*nax, 1);
VLL P;
vector<map<ll,ll>> factors; // keeps track of how many factors

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}

		P.push_back(x);
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}
}

ll pf(ll x) {
    ll ans = 1;
    REP(i,0,P.size()) {
        if (P[i] * P[i] > x) break;
        ll cnt = 1;
        while (x % P[i] == 0) {
            cnt++;
            x /= P[i];
        }
        ans *= cnt;
    }
    if (x > 1) ans *= 2;
    return ans;
}

const ll n = 1e6+5;

VLL goods;

void solve() {
    ll x;
    cin >> x;   
    
    ll L = 0, R = goods.size()-1;
    while (L<R) {
        ll M = (L+R)/2;
        if (goods[M] <= x) {
            L = M+1;
        } else {
            R = M;
        }
    }
    cout << goods[L-1] << endl;

}

signed main() {
	init();

    // hardcoded 
    goods = {1, 2, 3, 4, 6, 8, 10, 12, 18, 20, 24, 30, 36, 48, 60, 72, 84, 90, 96, 108, 120, 168, 180, 240, 336, 360, 420, 480, 504, 540, 600, 630, 660, 672, 720, 840, 1080, 1260, 1440, 1680, 2160, 2520, 3360, 3780, 3960, 4200, 4320, 4620, 4680, 5040, 7560, 9240, 10080, 12600, 13860, 15120, 18480, 20160, 25200, 27720, 30240, 32760, 36960, 37800, 40320, 41580, 42840, 43680, 45360, 50400, 55440, 65520, 75600, 83160, 98280, 110880, 131040, 138600, 151200, 163800, 166320, 196560, 221760, 262080, 277200, 327600, 332640, 360360, 393120, 415800, 443520, 471240, 480480, 491400, 498960, 554400, 655200, 665280, 720720, 831600, 942480, 982800, 997920, 1000010};

	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}