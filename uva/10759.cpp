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

namespace SOLVE {	
	VVLL waysdp(25, VLL(151, -1));
	VVLL sumdp(25, VLL(151, -1));

	ll ways(ll n, ll x) {
		if (n == 0 && x == 0) return 1;
		if (n == 0) return 0;
		if (x < n) return 0;
		if (x > 6*n) return 0;

		if (waysdp[n][x] != -1) return waysdp[n][x];

		ll ans = 0;
		REP(i,1,7) {
			ans += ways(n-1, x-i);
		}
		waysdp[n][x] = ans;
		return ans;
	}



	ll sum(ll n, ll x) {
		if (x > 6*n) return 0;
		if (sumdp[n][x] != -1) return sumdp[n][x];

		sumdp[n][x] = ways(n, x) + sum(n, x + 1);
		return sumdp[n][x];
	}

	ll pow(ll a, ll b) {
		if (b == 0) return 1;
		ll h = pow(a, b/2);
		ll ans = b % 2 ? h * h * a : h * h;
		return ans;
	}

	void main() {
		ll n, x;
		while (cin >> n >> x, n || x) {
			ll top = sum(n, x);
			ll bot = pow(6, n);

			if (top == bot) cout << 1 << endl;
			else if (top == 0) cout << 0 << endl;
			else {
				ll g = __gcd(top, bot);
				cout << top / g << "/" << bot / g << endl;
			}
		}
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
