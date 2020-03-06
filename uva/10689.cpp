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

ll mod = 1e9+7;
VVLL operator*(VVLL a, VVLL b) {
	VVLL c(a.size(), VLL(b[0].size()));
	
	REP(i,0,a.size()) {
		REP(j,0,a[0].size()) {
			REP(k,0,b[0].size()) {
				c[i][k] += a[i][j] * b[j][k];
				c[i][k] %= mod;
			}
		}
	}
	
	return c;			
}

VVLL operator^(VVLL a, ll k) {
	if (k == 1) {
		return a;
	}
	VVLL half = a ^ (k / 2);
	half = half * half;
	if (k % 2) {
		half = half * a;
	}
	return half;
}
void solve() {
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	mod = pow(10,m);

	VVLL A = {{1,1}, {1,0}};
	A = A^n;
	VVLL x = {{b}, {a}};
	VVLL ans = A*x;
	cout << ans[1][0] << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}