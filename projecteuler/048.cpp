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

const ll mod = 1e10;

namespace SOLVE {
	ll nax = 32;
	
	void proper(VLL & a) {
		REP(i,0,nax) {
			if (i != nax-1) a[i+1] += (a[i] / 10);
			a[i] %= 10;
		}
	}
	
	VLL to(ll x) {
		VLL A(nax);
		A[0] = x;
		proper(A);
		return A;
	}
	
	ll from(VLL A) {
		ll ans = 0;
		ll p = 1;
		REP(i,0,min(nax, 17LL)) {
			ans += p * A[i];
			p *= 10;
		}
		return ans;
	}
	
	// O(n)
	VLL operator+(VLL A, VLL B) {
		VLL C(nax);
		REP(i,0,nax) C[i] = A[i] + B[i];
		proper(C);
		return C;
	}
	
	// O(nlogb)
	VLL operator*(VLL A, VLL B) {
		ll b = from(B);
		if (b == 0) return to(0);
		VLL C = A * to(b/2);
		C = C+C;
		C = b%2 ? C+A : C;
		return C;
	}
	
	// O(nlogk)
	VLL operator^(VLL A, VLL K) {
		ll k = from(K);
		if (k == 0) return to(1);
		VLL C = A ^ to(k/2);
		C = C*C;
		C = k%2 ? C*A : C;
		return C;
	}
	 
	void main() {
		VLL ans(nax);
		ll n = 1000;
		REP(i,1,n+1) {
			ans = ans + (to(i) ^ to(i));
		}
		cout << from(ans) % mod << endl;
		
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
