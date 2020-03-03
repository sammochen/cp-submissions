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

string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
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

const ll inf = (ll)1e18 + 5;
namespace SOLVE {
	void main() {
		ll n, m, k;
		cin >> n >> m >> k;
		VLL A(n);
		REP(i,0,n) cin >> A[i];
		// i want to choose k sets of size m and maximise the sum
		VLL pre(n+1);
		REP(i,0,n) pre[i+1] = pre[i] + A[i];
		
		debug(A);
		debug(pre);
		
		vector<VLL> dp(n+1, VLL(k+1, 0)); // dp[i][j] max value that ends at i that contains j sets
		// dp[i][j] = max(dp[i-m][j-1] + sum(i -> j), dp[i-1][j])
		
		dp[0][0] = 0;
		REP(i,1,n+1) { // index
			REP(j,1,k+1) { // sets left
				// if cannot form j sets
				if (i >= j*m) {
					dp[i][j] = max(dp[i-m][j-1] + pre[i] - pre[i-m], dp[i-1][j]);
				}
			}
		}
		
		cout << dp[n][k] << endl;
				
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
