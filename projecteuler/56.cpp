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
	ll nax = 300; // length of number
	
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
	
	// can only divide by ll for now
	VLL operator/(VLL A, ll b) {
		VLL C(nax);
		RREP(i,nax-1,0) {
			if (i != 0) A[i-1] += A[i] % b * 10;
			A[i] /= b;
		}
		return A;
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
		VLL C = A * (B/2);
		C = C+C;
		C = b%2 ? C+A : C;
		return C;
	}	
	
	// O(nlogk)
	VLL operator^(VLL A, VLL K) {
		ll k = from(K);
		if (k == 0) return to(1);
		VLL C = A ^ (K/2);
		C = C*C;
		C = k%2 ? C*A : C;
		return C;
	}
	
	ll sum(VLL A) {
		ll ans = 0;
		for (ll a : A) ans += a;
		return ans;
	} 
	 
	void main() {
		ll ans = 0;
		ll n = 100;
		
		REP(a,1,n) {
			VLL A = to(a);
			VLL cur = to(1);
			
			REP(b,1,n) {
				cur = cur * A;
				ans = max(ans, sum(cur));
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
