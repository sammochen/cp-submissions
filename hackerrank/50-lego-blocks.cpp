/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;
const ll mod = 1000000007;

namespace SOLVE {	
	ll goodwalls(ll a, ll b);

	ll pow(ll a, ll b) {
		if (b == 0) return 1;
		ll h = pow(a, b/2);
		ll ans = b % 2 ? h * h % mod * a : h * h;
		ans %= mod;
		return ans;
	}

	VLL waydp(1001, -1);
	VVLL gooddp(1001, VLL(1001, -1));
	
	// returns numbers of ways to make a x 1 wall 
	ll ways(ll a) {
		if (a < 0) return 0;
		if (a == 0) return 1;
		if (waydp[a] != -1) return waydp[a];
		ll ans = 0;
		REP(i,1,5) ans += ways(a - i);
		ans %= mod;
		waydp[a] = ans;
		return ans;
	}

	ll allwalls(ll a, ll b) {
		return pow(ways(a), b);
	}

	// there are no cracks that go right through it
	ll goodwalls(ll a, ll b) {
		if (gooddp[a][b] != -1) return gooddp[a][b]; 
		ll ans = allwalls(a, b) % mod;
		REP(i,1,a) {
			ans -= goodwalls(i, b) * allwalls(a-i, b) % mod;
			ans += mod;
			ans %= mod;
		}
		gooddp[a][b] = ans;
		return ans;
	}
	
	void main() {
		ll n, m;
		cin >> n >> m;
		cout << goodwalls(m,n) << endl;

	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
