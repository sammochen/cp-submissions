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

string to_string(string s) {return s;}
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
	ll n = 1000;
	
	string divide(ll a, ll b, ll l) {
		if (l == 0) return "";
		return to_string(a/b) + divide(10*(a%b), b, l-1);
	}
	
	ll r(ll x) {
		string ans = divide(1,x,3*n);
		
		// test from midpoint, see if there is any other
		REP(i,1,x+1) {
			if (ans.substr(n,i) == ans.substr(n + i, i)) return i;
		}
		return -1;
	}
		
	void main() {
		ll ans = 0;
		REP(i,1,n) {
			debug(i, r(i));
			ans = max(ans, r(i));
		}
		
		cout << ans + 1 << endl; // the longest normally has recur of n-1
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
