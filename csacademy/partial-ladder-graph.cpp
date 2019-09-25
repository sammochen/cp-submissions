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
		if (k == 0) {
			VVLL A(a.size(), VLL(a.size()));
			REP(i,0,a.size()) A[i][i] = 1;
			return A;
		}
		VVLL half = a ^ (k / 2);
		half = half * half;
		if (k % 2) {
			half = half * a;
		}
		return half;
	}

	void main() {
		ll n;
		cin >> n;
		
		VVLL A = {{4,1}, {2,1}};
		A = A^(n-1);
		VVLL b = {{1}, {1}};
		VVLL ans = A*b;
		
		cout << ans[0][0] << endl;
		
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
