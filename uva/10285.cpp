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

namespace SOLVE {	
	ll n, m;
	VVLL A;
	VVLL dp;

	ll get(ll i, ll j) {
		if (dp[i][j] != -1) return dp[i][j];

		ll ans = 1;
		if (i != 0 && A[i-1][j] < A[i][j]) ans = max(ans, get(i-1, j) + 1); 
		if (j != 0 && A[i][j-1] < A[i][j]) ans = max(ans, get(i, j-1) + 1); 
		if (i != n-1 && A[i+1][j] < A[i][j]) ans = max(ans, get(i+1, j) + 1); 
		if (j != m-1 && A[i][j+1] < A[i][j]) ans = max(ans, get(i, j+1) + 1); 

		dp[i][j] = ans;
		return ans;
	}

	void main() {
		string name;
		cin >> name >> n >> m;

		A.clear();
		A.resize(n, VLL(m));

		dp.clear();
		dp.resize(n, VLL(m, -1));

		REP(i,0,n) {
			REP(j,0,m) {
				cin >> A[i][j];
			}
		}

		ll ans = 0;

		REP(i,0,n) {
			REP(j,0,m) {
				ans = max(ans, get(i,j));
			}
		}

		cout << name << ": " << ans << endl;
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
