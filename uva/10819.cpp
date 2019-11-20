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
	void main() {
		ll k, n;
		ll nax = 10500;

		while (cin >> k >> n) {
			vector<PLL> A(n); 
			REP(i,0,n) {
				cin >> A[i].first >> A[i].second;
			}

			VLL dp(nax, -1); // dp[i][j] gives max favours using i money and j things

			dp[0] = 0;
			REP(j,0,n) {
				RREP(i,nax-1,0) {
					if (dp[i] == -1) continue;

					ll nexti = i+A[j].first;
					if (nexti < nax) dp[nexti] = max(dp[nexti], dp[i] + A[j].second); 
				}
			}

			ll ans = 0;
			REP(i,0,k+1) {
				ans = max(ans, dp[i]);
				if (i > 1800) ans = max(ans, dp[i+200]);
			}
			cout << ans << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
