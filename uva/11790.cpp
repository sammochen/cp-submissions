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
	ll a;
	a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a;
	a = scanf("%lld", &x);
}

namespace SOLVE {	
	ll test = 1;
	void main() {
		ll n;
		in(n);
		VLL h(n), w(n);
		REP(i,0,n) in(h[i]);
		REP(i,0,n) in(w[i]);

		VLL lis(n), lds(n); 
		ll A = 0, B = 0;
		REP(i,0,n) {
			lis[i] = w[i];
			lds[i] = w[i];
		}
		REP(i,0,n) {
			REP(j,0,i) {
				if (h[i] > h[j]) lis[i] = max(lis[i], lis[j] + w[i]);
			}
			A = max(A, lis[i]);
		}
		RREP(i,n-1,0) {
			REP(j,i+1,n) {
				if (h[i] > h[j]) lds[i] = max(lds[i], lds[j] + w[i]);
			}
			B = max(B, lds[i]);
		}

		if (A >= B) {
			printf("Case %lld. Increasing (%lld). Decreasing (%lld).\n", test++, A, B);
		} else {
			printf("Case %lld. Decreasing (%lld). Increasing (%lld).\n", test++, B, A);
		}

	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
