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
	ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
	
	// simplify
	PLL s(PLL p) {
		ll a = p.first, b = p.second;
		ll g = gcd(a,b);
		return MP(a / g, b / g);
	}
	
	// fake
	PLL f(PLL p) {
		ll a = p.first, b = p.second;
		if (a/10 == b%10) return MP(a%10,b/10);
		if (a%10 == b/10) return MP(a/10,b%10);
		return MP(-1,1);
	}
			
		
	void main() {
		ll anstop = 1, ansbottom = 1;
		REP(bottom,10,100) {
			REP(top,10,bottom) {
				PLL p = MP(top,bottom);
				if (s(f(p)) == s(p)) anstop *= top, ansbottom *= bottom;
			}
		}
		
		cout << s(MP(anstop, ansbottom)).second << endl;
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
