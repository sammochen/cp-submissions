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

const ll mod = 1000007;

namespace SOLVE {	
	ll n;
	vector<string> A;
	VVLL dp;

	ll type(ll i, ll j) {
		if (j < 0 || j >= n) return 2;
		if (i < 0 || i >= n) return 2;
		return A[i][j] == '.' ? 1 : 0; 
	}

	ll get(ll i, ll j) {
		if (i < 0) return 0;
		if (i == 0) return 1;
		if (dp[i][j] != -1) return dp[i][j];

		ll ans = 0;

		if (type(i-1,j+1) == 1) ans += get(i-1, j+1);
		if (type(i-1,j-1) == 1) ans += get(i-1, j-1);
		if (type(i-1,j+1) == 0 && type(i-2,j+2) == 1) ans += get(i-2,j+2);
		if (type(i-1,j-1) == 0 && type(i-2,j-2) == 1) ans += get(i-2,j-2);

		ans %= mod;
		dp[i][j] = ans;

		return ans;

		
	}

	ll test = 1;

	void main() {
		cin >> n;
		A.resize(n);

		REP(i,0,n) cin >> A[i];

		dp.clear();
		dp.resize(n, VLL(n, -1));

		REP(i,0,n) {
			REP(j,0,n) {
				if (A[i][j] == 'W') {
					ll ans = get(i,j);
					printf("Case %lld: %lld\n", test++, ans);
					return;
				}
			}
		}



	}
}


signed main() {	
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
