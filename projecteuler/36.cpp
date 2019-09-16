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
	string R(string s) {
		reverse(s.begin(), s.end());
		return s;
	}
	
	string b(ll x) {
		if (x == 0) return "";
		string end = x % 2 ? "1" : "0";
		return b(x/2) + end;
	}
	
	ll pb(ll x) {
		string s = b(x);
		string r = R(s);
		if (r[0] == '0') return 0;
		return s == r;
	}
	
	void main() {
		ll n = 1000;
		ll nax = 1000000;
		ll ans = 0;
		
		vector<string> pos = {""};
		REP(i,0,10) pos.push_back(to_string(i));
		
		// one digit
		REP(i,1,10) {
			ll x = i;
			if (x <= nax && pb(x)) {
				ans += x;
			}
		}
		
		// more than one digit
		REP(i,1,n) {
			// ii
			// iji
			for (string p : pos) {
				ll x = stol(to_string(i) + p + R(to_string(i)));
				
				if (x <= nax && pb(x)) {
					ans += x;
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
