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
		ll N, Q;
		ll t = 1;
		while (cin >> N >> Q) {
			if (N == 0 && Q == 0) return;

			VLL A(N);
			REP(i,0,N) cin >> A[i];

			printf("SET %lld:\n", t++);

			REP(q,1,Q+1) {
				ll D, M;
				cin >> D >> M;

				// dp[ind][amount][div] - number of ways to use up to ind, choosing amount, summing to div mod D
				// base case: dp[0][0][0] = 1
				ll dp[205][15][25] = {0};
				dp[0][0][0] = 1;
				
				REP(i,1,A.size() + 1) { // i is 1-indexed
					REP(j,0,M+1) {
						REP(k,0,D) {
							dp[i][j][k] = dp[i-1][j][k];
							if (j != 0) dp[i][j][k] += dp[i-1][j-1][(k - (A[i-1]%D) + D) % D];
						}
					}
				}

				ll ans = dp[A.size()][M][0];

				printf("QUERY %lld: %lld\n", q, ans);
			}
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
