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
	string get(ll i) {
		if (i == 1) return "qaz";
		if (i == 2) return "wsx";
		if (i == 3) return "edc";
		if (i == 4) return "rfvtgb";
		if (i == 5) return " ";
		if (i == 6) return " ";
		if (i == 7) return "yhnujm";
		if (i == 8) return "ik,";
		if (i == 9) return "ol.";
		if (i == 10) return "p;/";
		return "";
	}

	void main() {
		ll n, m;
		while (cin >> n >> m) {
			map<char,ll> notgood;
			REP(i,0,n) {
				ll x;
				cin >> x;
				string s = get(x);
				for (char c : s) notgood[c] = 1;
			}

			set<string> ans;
			ll len = 0;

			REP(j,0,m) {
				string s;
				cin >> s;
				
				ll ok = 1;
				for (char c : s) {
					if (notgood[c]) ok = 0;
				}
				if (ok) {
					if (s.length() > len) {
						ans = {s};
						len = s.length();
					}
					else if (s.length() == len) ans.insert(s);
				}
			}

			cout << ans.size() << endl;
			for (string s : ans) cout << s << endl;


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
