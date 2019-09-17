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

const ll nax = 1000; // sqrt

namespace SOLVE {
	VLL p(nax*nax, 1);
	
	void pp() {
		p[0] = 0;
		p[1] = 0;

		for (ll x = 2; x < nax; x++) {
			if (p[x] == 0) {
				continue;
			}
			
			for (ll f = 2; x * f < nax * nax; f++) {
				p[x*f] = 0;
			}
		}
	}
	
	// distinct
	ll d(ll x) {
		ll ans = 0;
		ll f = 2;
		while (f * f <= x) {
			if (x % f == 0) {
				while (x % f == 0) x /= f;
				ans++;
			}
			f++;
		}
		
		ans += (x != 1);
		return ans;
	}
	
	void main() {
		if (p[0] == 1) pp();
		
		ll n = 1000000;
		VLL D(n); // keeps d[i]
		VLL four(n); // current streak of 4s
		
		ll ans;
		
		REP(i,1,n) {
			D[i] = d(i);
			four[i] = D[i] == 4 ? four[i-1] + 1 : 0;
			if (four[i] == 4) {
				ans = i - 3; 
				break;
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
