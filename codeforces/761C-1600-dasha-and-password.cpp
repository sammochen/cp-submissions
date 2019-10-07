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

const ll inf = 1e9+7;

namespace SOLVE {
	ll isnumber(char c) {
		return c >= '0' && c <= '9';
	}

	ll isletter(char c) {
		return c >= 'a' && c <= 'z';
	}

	ll issymbol(char c) {
		return c == '#' || c == '*' || c == '&';
	}

	VLL f(string s) {
		ll n = s.length();
		VLL ans(3, inf);
		REP(i,0,n) {
			if (isnumber(s[i])) {
				ans[0] = min({ans[0], i, n - i});
			}
			if (isletter(s[i])) {
				ans[1] = min({ans[1], i, n - i});
			}
			if (issymbol(s[i])) {
				ans[2] = min({ans[2], i, n - i});
			}
		}
		return ans;
	}	

	void main() {
		ll n, m;
		cin >> n >> m;
		vector<string> A(n);
		REP(i,0,n) cin >> A[i];

		VVLL fast(n, VLL(3)); // fast[s][0] is number, [1] is letter, [2] is symbol

		// precompute fast
		REP(i,0,n) {
			fast[i] = f(A[i]);
		}

		VVLL dp(n+1, VLL(8, inf)); // dp[i][mask] gives least steps to achieve up to i, satisfying mask
		dp[0][0] = 0;

		REP(i,0,n) {
			REP(j,0,8) {
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
				dp[i+1][j | 1] = min(dp[i+1][j | 1], dp[i][j] + fast[i][0]);
				dp[i+1][j | 2] = min(dp[i+1][j | 2], dp[i][j] + fast[i][1]);
				dp[i+1][j | 4] = min(dp[i+1][j | 4], dp[i][j] + fast[i][2]);
			}
		}

		ll ans = dp[n][7];
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
