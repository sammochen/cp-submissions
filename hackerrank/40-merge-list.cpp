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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

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

const ll mod = 1e9+7;
const ll nax = 2e5 + 5;

namespace SOLVE {	
	VLL F(nax, -1);
	VLL INVF(nax, -1);

	ll pow(ll a, ll b) {
		if (b == 0) return 1;
		ll h = pow(a, b/2);
		ll ans = b % 2 ? h * h % mod * a : h * h;
		ans %= mod;
		return ans;
	}

	ll f(ll x) {
		if (F[x] != -1) return F[x];
		if (x == 0) return 1;
		F[x] = f(x-1) * x % mod;
		return F[x];
	}

	ll invf(ll x) {
		if (INVF[x] != -1) return INVF[x];
		INVF[x] = pow(f(x), mod-2);
		return INVF[x];
	}

	ll ncr(ll n, ll r) {
		// n! / r! / (n-r)!
		ll ans = f(n);
		ans *= invf(r);
		ans %= mod;
		ans *= invf(n-r);
		ans %= mod;
		return ans;
	}

	
	void main() {
		ll a, b;
		cin >> a >> b;
		cout << ncr(a+b, b) << endl;
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}