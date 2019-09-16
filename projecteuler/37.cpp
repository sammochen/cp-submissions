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

const ll nax = 4000; // sqrt

namespace SOLVE {
	VLL p(nax*nax, 1);
	VLL S = {1,2,3,5,7,9};
	map<string,ll> f; 
	ll ans = -17; // -2 -3 -5 -7
	
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
	
	// recursive
	void r(string s, ll right) {
		if (right == 0) {
			f[s] = 1;
		} else {
			if (f[s] && s != "") {
				ans += stoll(s);
			}
		}
		
		for (ll i : S) {
			string a = right == 1 ? s + to_string(i) : to_string(i) + s;
			
			if (stoll(a) < nax * nax && p[stoll(a)]) {
				r(a, right);
			} 
		}
	}
	void main() {
		if (p[0] == 1) pp();
		
		r("", 0); // left
		r("", 1); // right
		
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
