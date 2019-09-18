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

const ll nax = 100; // guess of 10000

namespace SOLVE {
	VLL p(nax*nax, 1);
	VLL P, D;
	
	void init() {
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
		
		REP(i,0,nax*nax) {
			if (p[i]) P.push_back(i);
		}
		
		REP(i,1,nax) D.push_back(2*i*i);
	}
	
	
	void main() {
		init(); // sets up P list and D list
		
		map<ll,ll> f; // keeps track of all numbers that can be represented as p + 2*s
		
		for (ll prime : P) {
			for (ll square : D) {
				f[prime+square] = 1;
			}
		}
		
		ll ans;
		for (ll x = 3; x < nax*nax; x+=2) { // not including 1!
			if (!f[x] && !p[x]) {
				ans = x;
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
