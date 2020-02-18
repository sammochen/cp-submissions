#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll getll() {
		string s;
		getline(cin, s);
		return stoll(s);
	}
	void main() {
		ll n = getll();
		map<string,ll> dict;
		
		REP(i,0,n) {
			string s;
			getline(cin, s);
			dict[s] = i+1;
		}

		ll q = getll();
		REP(i,0,q) {
			string s;
			getline(cin, s);
			if (dict[s]) {
				printf("%s is correct\n", s.c_str());
				continue;
			}

			string ans = "-1";
			// add a letter
			REP(j,0,s.length() + 1) {
				for (char c = 'a'; c <= 'z'; c++) {
					string t = s.substr(0,j) + string(1, c) + s.substr(j);
					if (dict[t]) if (ans == "-1" || dict[t] < dict[ans]) ans = t;
				}
			}

			// delete a letter
			REP(j,0,s.length()) {
				string t = s.substr(0,j) + s.substr(j + 1);
				if (dict[t]) if (ans == "-1" || dict[t] < dict[ans]) ans = t;
			}

			// change a letter
			REP(j,0,s.length()) {
				for (char c = 'a'; c <= 'z'; c++) {
					string t = s;
					t[j] = c;
					if (dict[t]) if (ans == "-1" || dict[t] < dict[ans]) ans = t;
				}
			}

			// switch two adjacent letters
			REP(j,0,s.length() - 1) {
				string t = s;
				t[j] = s[j+1];
				t[j+1] = s[j];
				if (dict[t]) if (ans == "-1" || dict[t] < dict[ans]) ans = t;
				
			}

			if (ans == "-1") {
				printf("%s is unknown\n", s.c_str());
			} else {
				printf("%s is a misspelling of %s\n", s.c_str(), ans.c_str());
			}
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
