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

const ll inf = (ll)1e12;
namespace SOLVE {	
	void main() {
		ll n = 10, m;
		cin >> m;
		m /= 100;
		
		VVLL A(n,VLL(m));
		RREP(i,n-1,0) {
			REP(j,0,m) {
				cin >> A[i][j];
			}
		}

		VLL dp(n, inf);
		dp[0] = 0;

		REP(j,0,m) {
			VLL next(n, inf);
			REP(i,0,n) {
				
				if (i != n-1) next[i+1] = min(next[i+1], dp[i] + 60 - A[i][j]);
				next[i] = min(next[i], dp[i] + 30 - A[i][j]);
				if (i != 0) next[i-1] = min(next[i-1], dp[i] + 20 - A[i][j]);
			
			}
			dp = next;
		}

		ll ans = dp[0];
		cout << ans << endl << endl;;

	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
