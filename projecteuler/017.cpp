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
	map<ll, string> w;

	string word(ll x) {
		if (x == 0) {
			return w[0];
		}
		string ans = "";
		if (x / 1000) {
			ans += w[x / 1000] + " thousand";
			x = x % 1000;
			if (x) ans += " and ";
		}
		if (x / 100) {
			ans += w[x / 100] + " hundred";
			x = x % 100;
			if (x) ans += " and ";
		}
		if (x > 20) {
			ans += w[x / 10 * 10];
			x = x % 10;
			if (x) ans += " ";
		} 
		if (x != 0) {
			ans += w[x];
		}
		return ans;
	}
	
	void init() {
		w[0] = "zero";
		w[1] = "one";
		w[2] = "two";
		w[3] = "three";
		w[4] = "four";
		w[5] = "five";
		w[6] = "six";
		w[7] = "seven";
		w[8] = "eight";
		w[9] = "nine";
		w[10] = "ten";
		w[11] = "eleven";
		w[12] = "twelve";
		w[13] = "thirteen";
		w[14] = "fourteen";
		w[15] = "fifteen";
		w[16] = "sixteen";
		w[17] = "seventeen";
		w[18] = "eighteen";
		w[19] = "nineteen";
		w[20] = "twenty";
		w[30] = "thirty";
		w[40] = "forty";
		w[50] = "fifty";
		w[60] = "sixty";
		w[70] = "seventy";
		w[80] = "eighty";
		w[90] = "ninety";
		w[100] = "hundred";
		w[1000] = "thousand";
	}
		
	
	void main() {
		init();
		
		ll n = 1000;
		string all = "";
		
		REP(i,1,n+1) {
			all += word(i);
		}
		
		ll ans = 0;
		for (char c : all) {
			ans += (c != ' ');
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
