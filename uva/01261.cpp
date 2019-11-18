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
	map<string,ll> memo;
	map<string,ll> done;

	ll get(string s) {
		if (done[s]) return memo[s];

		if (s == "") return 1;
		
		ll first = 0;
		char cur = s[0];

		ll ans = 0;

		REP(i,1,s.length()) {
			if (s[i] != cur) {
				// change in block
				string popped = s.substr(0,first) + s.substr(i);
			
				if (popped.length() + 1 != s.length()) {
					ans |= get(popped);
				}

				cur = s[i];
				first = i;
			}
		}

		string popped = s.substr(0,first);
			
		if (popped.length() + 1 != s.length()) {
			ans |= get(popped);
		}
		
		done[s] = 1;
		memo[s] = ans;
		return ans;
	}

	void main() {
		string s;
		cin >> s;

		cout << get(s) << endl;

	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
