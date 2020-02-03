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
const ll mod = 1e9+7;
const ll nax = 1e5+5;

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
		if (r > n) return 0;
		// n! / r! / (n-r)!
		ll ans = f(n);
		ans *= invf(r);
		ans %= mod;
		ans *= invf(n-r);
		ans %= mod;
		return ans;
	}

	ll makemod(ll x) {
		x %= mod;
		x += mod;
		x %= mod;
		return x;
	}

	void main() {
		ll n, k;
		cin >> n >> k;
		VLL A(n);
		REP(i,0,n) {
			cin >> A[i];
		}

		sort(A.begin(), A.end());
		ll ans = 0;

		REP(i,0,n) {
			// see how many ways this number is big
			ans += makemod(A[i] * ncr(i, k-1));
			ans -= makemod(A[i] * ncr(n-i-1, k-1));
			ans = makemod(ans);
		}

		cout << ans << endl;
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
