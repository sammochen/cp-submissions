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
	scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	scanf("%lld", &x);
}

template<typename A,typename B > inline void in(A&x,B&y) {in(x);in(y);}
template<typename A,typename B,typename C>inline void in(A&x,B&y,C&z) {in(x);in(y);in(z);}
template<typename A,typename B,typename C,typename D> inline void in(A&x,B&y,C&z,D&d) {in(x);in(y);in(z);in(d);}

namespace SOLVE {	
	void main() {
		ll n, m;
		in(n,m);
	}
}


signed main() {
	ll t;
	t = 1;
	// in(t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
