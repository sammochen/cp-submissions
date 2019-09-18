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
	ll p(ll x) {
		return (x * (3*x - 1) / 2);
	}
	
	void main() {
		map<ll,ll> P;
		REP(i,1,10000) P[p(i)] = 1;
		
		ll n = 2000; // guess
		
		// p1, p2, p3, p4
		// p3 - p2 = p1
		// p2 + p3 = p4
		// if we iterate up from p1, the first answer is the answer that minimises p3 - p2
		
		ll ans;
		
		REP(i,1,n) { // p1
			REP(j,1,n) { // p2
				ll a = p(i), b = p(j);
				
				if (p(j+1) - p(j) > p(i)) break; 
				if (P[a+b] && P[a+2*b]) ans = a;
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
