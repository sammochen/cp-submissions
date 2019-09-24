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

namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;
		VLL A;
		ll x, ans = 0, added = 0;
		REP(i,0,n) {
			cin >> x;
			if (x >= 0) {
				ans += x;
				added = 1;
			} else {
				A.push_back(x);
			}
		}
		
		if (n == 1) {
			ans = A[0];
			cout << ans << endl;
			return;
		}
		
		sort(A.rbegin(), A.rend());
		
		ll m = A.size();
		VLL dp(m);
		
		dp[m-1] = A[m-1];
		dp[m-2] = A[m-2];
		
		RREP(i,m-3,0) {
			dp[i] = max(dp[i+1], dp[i+2]) + A[i];
		}
		
		if (added) ans += max(dp[0], dp[1]);
		else ans += dp[0];
		
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
