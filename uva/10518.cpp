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

namespace SOLVE {
	ll mod = 1e9 + 7;
	
	VVLL operator*(VVLL a, VVLL b) {
		VVLL c(a.size(), VLL(b[0].size()));
		
		REP(i,0,a.size()) {
			REP(j,0,a[0].size()) {
				REP(k,0,b[0].size()) {
					c[i][k] += a[i][j] * b[j][k];
					c[i][k] %= mod;
				}
			}
		}
		
		return c;			
	}
	
	VVLL operator^(VVLL a, ll k) {
		if (k == 1) {
			return a;
		}
		VVLL half = a ^ (k / 2);
		half = half * half;
		if (k % 2) {
			half = half * a;
		}
		return half;
	}

	ll test = 1;
	void main() {
		ll a, b;
		VVLL A = {
			{1,0,0},
			{0,0,1},
			{1,1,1}
		};

		while (cin >> a >> b, a != 0 || b != 0) {
			mod = b;
			VVLL B = A;
			if (a > 0) B = A ^ a;
			
			VVLL X = {{1},{1},{1}};

			VVLL ans = B * X;
			printf("Case %lld: %lld %lld %lld\n", test++, a, b, ans[1][0]);
		}
		
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
