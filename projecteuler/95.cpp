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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

namespace SOLVE {
	ll n = 1000000;
	VLL L(n+1, -1); // longest amicable chain length
	VLL D(n+1, -1);
	
	// divisors
	ll d(ll x) {
		if (x > n || x <= 0) return 0;
		if (D[x] != -1) return D[x];
		
		ll t = -x;
		for (ll f = 1; f * f <= x; f++) {
			if (x % f == 0) {
				t += f;
				t += f * f == x ? 0 : x / f;
			}
		}
		t = t > n ? 0 : t;
		D[x] = t;
		return t;
	}
	
	// three possibilities:
	// 0. undiscovered: -1
	// 1. point goes all the way to 0, out of bounds, or to a loop: -2
	// 2. point is in a cycle: (length of cycle)
	
	ll l(ll x) {
		if (x > n || x <= 0) return -2;
		if (L[x] != -1) return L[x];
		
		map<ll,ll> current; // keeps track of current path's distance
		VLL path; // numbers on the current path
		
		ll xx = x; // pointer
		ll dist = 1;
		while (1) { // traverse
			path.push_back(xx);

			current[xx] = dist++;
			xx = d(xx);
			
			// moved forward!
			if (L[xx] == -2) { // if it eventually goes to 0, out of bounds or another loop
				for (ll p : path) {
					L[p] = -2;
				}
				return L[x];
			}
			if (current[xx] != 0) { // if xx has been stepped on!
				if (xx == x) {
					for (ll p : path) {
						L[p] = dist - 1;
					}
					return L[x];
				} else {
					ll number = -2;
					for (ll p : path) {
						if (p == xx) number = dist - current[xx];
						L[p] = number;
					}
					return L[x];
				}
			}
		}
		return -2;
	}
	
	void main() {	
		ll length = 0;
		ll ans = 0;
		
		REP(i,1,n) {
			if (l(i) > length) {
				length = l(i);
				ans = i;
			} 
		}
		
		cout << ans << endl;
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
