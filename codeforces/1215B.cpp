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

namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) cin >> A[i];

		VVLL dp(n+1, VLL(2)); // dp[i][0] is how many subsegments are positive, dp[1] is negative
		
		REP(i,1,n+1) {

			if (A[i-1] < 0) {
				dp[i][0] = dp[i-1][1];
				dp[i][1] = dp[i-1][0] + 1;
			} else {
				dp[i][0] = dp[i-1][0] + 1;
				dp[i][1] = dp[i-1][1];
			}
		}

		ll neg = 0, pos = 0;
		REP(i,1,n+1) {
			pos += dp[i][0];
			neg += dp[i][1];
		}
		
		cout << neg << ' ' << pos << endl;


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
