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

string to_string() { return ""; }
string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
template <typename A> string to_string(vector<A> v) { string s = "("; int f = 1; for (A a : v) { if (!f) { s += ", "; } f = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename... B> string to_string(A AA, B... BB) { return to_string(AA) + " " + to_string(BB...); }

// #define ONLINE_JUDGE 1
#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]: ", cerr << to_string(__VA_ARGS__) << endl; } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

const string fail = "Just a legend";

namespace SOLVE {
	void main() {
		string s;
		cin >> s;
		ll n = s.size();
		// kmp - prefix function
		VLL p(n); // p[i] is length of longest suffix ending at i that is also a prefix (not inc start)
		
		REP(i,1,n) {
			ll ind = i - 1;
			while (ind >= 0) {
				if (s[i] == s[p[ind]]) {
					p[i] = p[ind] + 1;
					break;
				}
				
				ind = p[ind] - 1;
			}
		}
			
		if (p[n-1] == 0) { // suffix is not prefix at all
			cout << fail << endl;
			return;
		}
		
		REP(i, 1, n - 1) { 
			if (p[i] == p[n-1]) {
				cout << s.substr(0, p[n-1]) << endl;
				return;
			}
		}
		
		if (p[p[n-1]-1] != 0) {
			cout << s.substr(0, p[p[n-1]-1]) << endl;
			return;
		}
		
		cout << fail << endl;
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
