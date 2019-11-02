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
	ll n;
	VVLL A;
	VVLL dp;
	
	// returns max for some row and a bitmask of cannot
	// O(n^2 * 2^n) solution (i think)
	ll get(ll row, ll cannot) {
		if (row == n) return 0;

		if (dp[row][cannot] == -1) {
			ll best = 0;
			REP(i,0,n) {
				ll nextcannot = cannot | (1<<i);
				if (cannot != nextcannot) {
					best = max(best, get(row+1, nextcannot) + A[row][i]);
				}
			}
			dp[row][cannot] = best;
		}
		return dp[row][cannot];
	}

	void main() {
		n = 15;
		A.resize(n, VLL(n));
		dp.resize(n, VLL(1LL<<n, -1));

		// take the 15x15 grid as input
		REP(i,0,n) {
			REP(j,0,n) {
				cin >> A[i][j];
			}
		}

		ll ans = get(0,0);
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
