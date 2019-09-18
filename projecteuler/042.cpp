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
	string in() {
		string ans = "";
		int on = 0;
		char c;
		
		while (cin >> c) {
			if (c == '"') on++;
			else if (on == 1) ans += c;
			else if (on == 2) return ans;
		}
		return "-";
	}
	
	ll t(ll x) {
		return x * (x + 1) / 2;
	}
	
	ll v(string s) {
		ll ans = 0;
		for (char c : s) ans += (c - 'A' + 1);
		return ans;
	} 
			
	void main() {
		map<ll,ll> T;
		REP(i,0,1000) T[t(i)] = 1;
		
		ll ans = 0;
		
		while (1) {
			string s = in();
			if (s == "-") break;
			if (T[v(s)]) ans++;		
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
