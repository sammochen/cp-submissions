/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include "bigint.cpp"

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
		bigint x;
		
		bigint inv = -1000000007;

		bigint ans = inv;
		vector<bigint> dp = {inv, inv}; // keep track of pos and neg

		// trying a O(n) solution
		while (cin >> x) {
			vector<bigint> next = {inv, inv};

			if (x == -999999){
				cout << ans << endl;
				ans = inv;
			} else {
				if (dp[0] == inv && dp[1] == inv) {
					next[0] = x;
					next[1] = x;
				} else if (dp[0] == inv) {
					next[0] = x;
					next[1] = min(x, dp[1] * x);
				} else if (dp[1] == inv) {
					next[0] = max(x, dp[0] * x);
					next[1] = x;
				} else {
					next[0] = max({x, dp[0] * x, dp[1] * x});
					next[1] = min({x, dp[0] * x, dp[1] * x});
				}
			}

			dp = next;
			ans = max({ans, next[0], next[1]});
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
