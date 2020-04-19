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
typedef vector<VVLL> VVVLL;

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template<typename A,typename B > inline void in(A&x,B&y) {in(x);in(y);}
template<typename A,typename B,typename C>inline void in(A&x,B&y,C&z) {in(x);in(y);in(z);}
template<typename A,typename B,typename C,typename D> inline void in(A&x,B&y,C&z,D&d) {in(x);in(y);in(z);in(d);}

const ll mod = 1e9+7;

namespace SOLVE {	
	VVVLL dp;
	vector<vector<PLL>> M;

	ll get(ll i, ll j, ll k) {
		if (i < 0 || j < 0 || k < 0) return 0;
		if (i == 0 && j == 0 && k == 0) return 1;
		if (dp[i][j][k] != -1) return dp[i][j][k];

		ll zerocount = ((i == 0) + (j == 0) + (k == 0));

		if (zerocount < 2) {
			if ((i == j) || (j == k) || (k == i)) {
				dp[i][j][k] = 0;
				return 0;
			}
		}

		ll m = max({i,j,k});
		for (PLL p : M[m]) {
			ll count = ((i >= p.first) + (j >= p.first) + (k >= p.first));
			if (count != p.second) {
				dp[i][j][k] = 0;
				return 0;
			}
		}
		
		
		ll ans = 0;
		if (m == i) {
			if (i-1 == j || i-1 == k) {
				REP(x,0,i) ans += get(x,j,k);
			} else ans = get(i-1,j,k);
		}

		if (m == j) {
			if (j-1 == i || j-1 == k) {
				REP(x,0,j) ans += get(i,x,k);
			} else ans = get(i,j-1,k);
		}

		if (m == k) {
			if (k-1 == i || k-1 == j) {
				REP(x,0,k) ans += get(i,j,x);
			} else ans = get(i,j,k-1);
		}
		ans %= mod;
		dp[i][j][k] = ans;
		return dp[i][j][k];
	}

	void main() {
		ll n, m;
		in(n,m);

		dp.resize(n+1,VVLL(n+1, VLL(n+1, -1)));
		M.resize(n+1);

		REP(i,0,m) {
			ll a, b, c;
			in(a,b,c);
			M[b].push_back({a,c});
		}
		

		ll ans = 0;
		REP(i,0,n+1) {
			REP(j,0,n+1) {
				REP(k,0,n+1) {
					if (i == n || j == n || k == n) ans += get(i,j,k);
				}
			}
		}


		cout << ans << endl;
		

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
