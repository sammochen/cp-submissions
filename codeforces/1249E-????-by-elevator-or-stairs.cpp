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
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	void main() {
		ll n, c;
		cin >> n >> c;
		VLL A(n), B(n);
		REP(i,1,n) cin >> A[i];
		REP(i,1,n) cin >> B[i];
		
		VVLL dp(n, VLL(2)); // dp[i][0] is cost of the last step being stairs, dp[i][1] is last step being lift
		dp[0][1] = inf;

		REP(i,1,n) {
			dp[i][0] = min(dp[i-1][0] + A[i], dp[i-1][1] + A[i]);
			dp[i][1] = min(dp[i-1][0] + B[i] + c, dp[i-1][1] + B[i]);
		}

		REP(i,0,n) {
			cout << min(dp[i][0], dp[i][1]) << ' ';
		}
		cout << endl;
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
