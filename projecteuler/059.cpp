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
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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
	ll good(string & s, string & bad) {
		for (char letter : s) {
			for (char badletter : bad) {
				if (letter == badletter) {
					return 0;
				}
			}
		}
		return 1;
	}

	void main() {
		string s;
		cin >> s;
		s += ",";
		VLL A;
		ll num = 0;
		for (char c : s) {
			if (c == ',') {
				A.push_back(num);
				num = 0;
			} else {
				num = num * 10 + (c - '0');
			}
		}
			
		ll ans = 0;
		REP(i,97,123) {
			REP(j,97,123) {
				REP(k,97,123){
					VLL key = {i,j,k};
					string message = "";
					string bad = "<>`~";
					REP(i,0,A.size()) {
						message += (A[i] ^ key[i%3]);
					}
					
					if (good(message, bad)) {
						debug(message);
						for (char c : message) {
							ans += c;
						}
					}

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
