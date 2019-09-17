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
	VLL div = {0,0,0,0,2,3,5,7,11,13,17};
	ll ans = 0;
	
	ll in(string s, char c) {
		for (char ss : s) {
			if (c == ss) {
				return 1;
			}
		}
		return 0;
	}
	
	void p(string s) {
		if (s.size() > 3) {
			if (stol(s.substr(s.size() - 3)) % div[s.size()] != 0) return;
		}
		if (s.size() == 10) {
			ans += stol(s);
		}
		for (char c = '0'; c <= '9'; c++) {
			if (!in(s, c)) {
				p(s + c);
			}
		}
	}
		
	void main() {
		p("");
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
