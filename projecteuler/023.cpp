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

namespace SOLVE {
	ll nax = 30000; // guess
	VLL d(nax, -1);
	
	ll get(ll x) { // solve d and return
		if (d[x] != -1) return d[x];
		ll t = -x;
		for (ll f = 1; f * f <= x; f++) {
			if (x % f == 0) {
				t += f;
				t += f * f == x ? 0 : x / f;
			}
		}
		d[x] = t;
		return t;
	}
	
	void main() {
		// once you get 12 in a row, its done
		VLL dp(nax); // achievable as sum of abundants
		VLL abundants;
		REP(i,1,nax) {
			if (get(i) > i) abundants.push_back(i);
		}

		for (ll i : abundants) {
			for (ll j : abundants) {
				if (i + j < nax) {
					dp[i+j] = 1;
				}
			}
		}
		
		ll ans = 0;
		REP(i,0,nax) {
			if (dp[i] == 0) ans += i;
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
