#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

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
	if (k == 0) {
		VVLL b(a.size(), VLL(a.size()));
		REP(i,0,a.size()) b[i][i] = 1;
		return b;
	}
	VVLL half = a ^ (k / 2);
	half = half * half;
	if (k % 2) {
		half = half * a;
	}
	return half;
}

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

void solve() {
	ll n, a, b;
	in(n,a,b,mod);

	VLL count(19);
	RREP(d,18,1) {
		// i will add however many d digit numbers there are
		ll l = 0, r = n;
		ll limit = stoll(string(d, '9'));
		
		while (l < r) {
			ll m = (l+r)/2;

			if (a+m*b <= limit) l = m+1;
			else r = m;
		}
		count[d] = l;
	}
	RREP(i,18,1) {
		count[i] -= count[i-1];
	}

	ll ans = 0;
	ll cur = a;
	REP(i,1,19) {
		VVLL A = {
			{pow(10LL,i), 1, 0},
			{0, 1, b%mod},
			{0,0,1}
		};
		VVLL x = {{ans},{cur},{1}};
		
		VVLL Apow = A^(count[i]);
		VVLL res = Apow*x;

		ans = res[0][0];
		cur = res[1][0];
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}