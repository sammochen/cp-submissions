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

const ll inf = (ll)1e18;
namespace SOLVE {	

	void main() {
		ll n, m;
		while (cin >> n >> m) {
			VVLL A(n, VLL(m));
			

			REP(i,0,n) {
				REP(j,0,m) {
					cin >> A[i][j];
				}
			}

			VVLL dp(n, VLL(m));
			vector<vector<string>> path(n, vector<string>(m));

			REP(i,0,n) {
				dp[i][0] = A[i][0];
				path[i][0] = to_string(i);
			}

			REP(j,1,m) {
				REP(i,0,n) {
					dp[i][j] = inf;
					REP(k,-1,2) {
						ll lasti = (i+n+k)%n;
						ll newcost = dp[lasti][j-1] + A[i][j];
						if (newcost == dp[i][j]) {
							path[i][j] = min(path[i][j], path[lasti][j-1] + to_string(i));
						} else if (newcost < dp[i][j]) {
							path[i][j] = path[lasti][j-1] + to_string(i);
						}

						dp[i][j] = min(dp[i][j], dp[(i+n+k)%n][j-1] + A[i][j]);
					}
				}
			}

			ll ans = inf;
			string pathans;
			REP(i,0,n) {
				if (dp[i][m-1] == ans) {
					pathans = min(pathans, path[i][m-1]);
				} else if (dp[i][m-1] < ans) {
					pathans = path[i][m-1];
					ans = dp[i][m-1];
				}
			}

			REP(i,0,pathans.length()) {
				ll num = pathans[i] - '0';
				cout << num + 1;
				if (i == pathans.length() - 1) cout << endl;
				else cout << ' ';
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
