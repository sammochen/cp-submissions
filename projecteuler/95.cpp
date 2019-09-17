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
		D[x] = t;
		return t;
	}
	
	// returns the size of loop, 1 if itself, 0 if no loop
	ll loop(ll x) {
		if (x > n || x <= 0) return 0;
		if (L[x] != -1) return L[x];
		
		map<ll, ll> M;
		
		ll moves = 1;
		M[x] = moves++;
		ll xx = d(x);
		while (M[xx] == 0) {
			M[xx] = moves++;
			xx = d(xx);
			
			// if xx has been previously explored and was not a loop,
			if (0 <= xx && xx <= n && L[xx] == 0) {
				L[x] = 0;
				return 0;
			}
		}
		L[x] = xx == x ? moves - 1 : 0;
		return L[x];
	}
	
	// finds length of loop starting at x, 0 if no loop
	ll l(ll x) {
		if (x > n || x <= 0) return 0;
		if (L[x] != -1) return L[x];
		
		if (loop(x) != 0) return loop(x);
		L[x] = 0;
		l(d(x));
		return L[x];
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
