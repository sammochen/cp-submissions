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

const ll nax = 500; // sqrt

namespace SOLVE {
	VLL p(nax*nax, 1);
	VLL P;
	
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

		REP(i,1,nax*nax) {
			if (p[i]) P.push_back(i);
		}
	}

	ll T(ll x) {
		return x * (x - 1) / 2;
	}
	
	void main() {
		if (p[0] == 1) pp();
		
		ll n, k;
		cin >> n >> k;

		k = T(n) - k; // k is now how many (a,b) have gcd(a,b) = 1

		// find the smallest triangle number 
		ll t; // two is multiplied up to t
		REP(i,0,1e18) {
			if (T(i) > k) {
				t = i-1;
				break;
			}
		}

		ll u = k - T(t); // three is multipled up to u, as well as t+1

		REP(i,0,n) {
			ll x = P[i+2];
			if (i < t) x *= 2;
			if (i < u || i == t) x *= 3;
			 
			cout << x << ' ';
		}

		cout << endl;



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
