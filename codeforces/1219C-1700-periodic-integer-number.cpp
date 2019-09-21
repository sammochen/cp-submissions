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
	string make(string s, ll n) {
		if (n == 1) return s;
		string half = make(s, n/2);
		half = half + half;
		if (n%2) half = half + s;
		return half;
	}
	
	string onezero(ll n) {
		return "1" + string(n-1, '0');	
	}
	
	string oneup(string s) {
		ll carry = 0;
		s[s.length() - 1]++;
		
		RREP(i, s.length() - 1, 0) {
			s[i] += carry;
			carry = 0;
			
			if (s[i] > '9') {
				s[i] = '0';
				carry = 1;
			}
		}
		return s;
	}
	
	void main() {
		ll n;
		string s;
		cin >> n >> s;
		ll N = s.length();
		
		string ans;
		
		if (N % n != 0 || s.substr(0, n) == string(n, '9')) {
			ans = make(onezero(n), N/n + 1);
		} else {
			ans = make(s.substr(0,n), N/n);
			if (ans <= s) ans = make(oneup(s.substr(0,n)), N/n);
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
