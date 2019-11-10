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
		ll n, m;
		ll first = 1;
		while (cin >> n >> m) {
			if (!first) cout << endl;
			first = 0;
			
			VVLL A(n, VLL(n));
			REP(i,0,n) REP(j,0,n) cin >> A[i][j];
			
			VVLL pre(n+1, VLL(n+1));
			REP(i,1,n+1) {
				REP(j,1,n+1) {
					pre[i][j] = A[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
				}
			}

			ll total = 0;
			REP(i,0,n-m+1) {
				REP(j,0,n-m+1) {
					ll ans = pre[i+m][j+m] - pre[i][j+m] - pre[i+m][j] + pre[i][j];
					total += ans;
					cout << ans << endl;
				}
			}
			cout << total << endl;
		}
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
