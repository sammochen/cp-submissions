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
template <typename A> string to_string(pair<A,A> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
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
		ll n, m;
		cin >> n >> m;
		VVLL A(n, VLL(m));
		REP(i,0,n) {
			REP(j,0,m) cin >> A[i][j];
		}
		
		// make a streak kinda thing
		vector<vector<PLL>> dp(n, vector<PLL>(m)); // keeps track of biggest rectangle that ends at dp[i][j] with 0 on top and left
		
		REP(i,1,n) {
			REP(j,1,m) {
				if (A[i][j] == 0) {
					dp[i][j] = {0,0};
				} else if (dp[i-1][j].first == 0 && dp[i][j-1].first == 0) {
					if (A[i-1][j] == 0 && A[i][j-1] == 0 && A[i-1][j-1] == 0) {
						dp[i][j] = {i+1,j+1};
					}
				} else if (A[i-1][j] == 0 && dp[i][j-1].first == i+1) {
					dp[i][j] = dp[i][j-1];
				} else if (A[i][j-1] == 0 && dp[i-1][j].second == j+1) {
					dp[i][j] = dp[i-1][j];
				} else if (dp[i-1][j] == dp[i][j-1]) {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		vector<vector<PLL>> zeros(n, vector<PLL>(m));
		// keep track of streak of 0s - dp[i][j] is vertical, horizontal
		// this takes care of right and bottom 0s
		REP(i,0,n) {
			REP(j,0,m) {
				zeros[i][j].first = i == 0 ? !A[i][j] : A[i][j] ? 0 : zeros[i-1][j].first + 1;
				zeros[i][j].second = j == 0 ? !A[i][j] : A[i][j] ? 0 : zeros[i][j-1].second + 1;
			}
		}
		
		ll ans = -1;
		REP(i,0,n-1) {
			REP(j,0,m-1) {
				// find rectangle that satisfies both
				if (dp[i][j].first == 0) continue;
				ll di = i + 2 - dp[i][j].first;
				ll dj = j + 2 - dp[i][j].second;
				if (zeros[i+1][j+1].first >= di + 2) {
					if (zeros[i+1][j+1].second >= dj + 2) {
						ans = max(ans, di*dj);
					}
				}
				
			}
		}
		
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
