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

namespace SOLVE {
	void main() {
		ll n = 20, k = 4;
		vector<VLL> A(n, VLL(n));
		
		REP(i,0,n) {
			REP(j,0,n) {
				cin >> A[i][j];
			}
		}
		
		ll ans = 0;
		REP(i,0,n) {
			REP(j,0,n) {
				
				if (i >= k-1) {
					ll v = 1;
					REP(x,0,4) {
						v *= A[i-x][j];
					}
					ans = max(ans, v);
				} 
				
				if (j >= k-1) {
					ll v = 1;
					REP(x,0,4) {
						v *= A[i][j-x];
					}
					ans = max(ans, v);
				} 
				
				if (i >= k-1 && j >= k-1) {
					ll v = 1;
					REP(x,0,4) {
						v *= A[i-x][j-x];
					}
					ans = max(ans, v);
				} 
				
				if (i >= k-1 && j <= n-k) {
					ll v = 1;
					REP(x,0,4) {
						v *= A[i-x][j+x];
					}
					ans = max(ans, v);
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
