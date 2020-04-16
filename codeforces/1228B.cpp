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
const ll mod = 1e9+7;

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	VLL A(n), B(m);

	VVLL grid(n, VLL(m));

	REP(i,0,n) {
		ll x;
		cin >> x;
		REP(j,0,x) {
			grid[i][j] = 2;
		}
		if (x < m) grid[i][x] = 1;
	}

	REP(j,0,m) {
		ll x;
		cin >> x;
		REP(i,0,x) {
			if (grid[i][j] == 1) {
				cout << 0 << endl;
				return;
			}
			grid[i][j] = 2;
		}
		if (x < n) {
			if (grid[x][j] == 2) {
				cout << 0 << endl;
				return;
			}
			grid[x][j] = 1;
		}
	}
	ll free = 0;
	REP(i,0,n) {
		REP(j,0,m) {
			if (grid[i][j] == 0) free++;
		}
	}

	ll ans = pow(2LL, free);
	cout << ans << endl;

	



}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}