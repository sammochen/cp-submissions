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

const ll inf = (ll)1e18 + 7;
namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;
		// as i iterate, i keep track of current sum and smallest even/odd

		VLL dp(2);
		dp[0] = -inf - 1;
		dp[1] = -inf;
		
		ll x;
		REP(i,0,n) {
			cin >> x;
			VLL next(2);
			
			if (x%2 != 0) { // if current is odd
				next[1] = max(x, max(dp[0] + x, dp[1]));
				next[0] = max(dp[1] + x, dp[0]);
			} else { // if current is even
				next[0] = max(x, max(dp[0] + x, dp[0]));
				next[1] = max(dp[1] + x, dp[1]);
			}
			dp = next;
		}
		
		cout << dp[1] << endl;
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
