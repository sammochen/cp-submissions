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
	map<ll, map<ll, map<ll, ll>>> dp;
	map<ll, map<ll, map<ll, ll>>> done;

	// Build dp, top-down
	ll get(ll i, ll j, ll open) {
		if (done[i][j][open]) {
			return dp[i][j][open];
		}

		if (i == 0 && j == 0) {
			done[i][j][open] = 1;
			dp[i][j][open] = open != 0;
			return dp[i][j][open];
		}

		if (i < 0 || j < 0) {
			done[i][j][open] = 1;
			dp[i][j][open] = 0;
			return dp[i][j][open];
		} 

		if (open < 0) {
			done[i][j][open] = 1;
			dp[i][j][open] = get(i-1, j, -1) + get(i, j-1, -1);
			return dp[i][j][open];
		}
		
		// either ( or )
		done[i][j][open] = 1;
		dp[i][j][open] = get(i-1, j, open+1) + get(i, j-1, open-1);
		//debug(i, j, open);
		return dp[i][j][open];
	}

	// Build solution
	string index(ll i, ll j, ll open, ll ind) {
		if (i == 0 && j == 0) {
			return "";
		}

		ll getOpen = get(i-1, j, open < 0 ? -1 : open + 1);
		if (ind <= getOpen) {
			// it is a (
			return "(" + index(i-1, j, open < 0 ? -1 : open + 1, ind);
		} else {
			return ")" + index(i, j-1, open - 1, ind - getOpen);
		}
	}

	void main() {
		// dp[i][j][open] is how many bad sequences there are with i open, j close and current open
		// O(N^3) solution (enough for N = 30)

		ll n, k;
		cin >> n >> k;

		cout << index(n,n,0,k) << endl;
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
