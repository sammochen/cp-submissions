#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

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
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

void solve() {
	string s, t;
	ll first = 1;
	while (cin >> s >> t) {
		if (!first) cout << endl;
		first = 0;

		map<string,ll> A;
		REP(i,0,s.length()) {
			string sub = "";
			REP(j,i,s.length()) {
				sub.push_back(s[j]);
				A[sub] = 1;
			}
		}

		set<string> ans;
		ll len = 0;
		REP(i,0,t.length()) {
			string sub = "";
			REP(j,i,t.length()) {
				sub.push_back(t[j]);
				if (A[sub]) {
					if (sub.length() > len) {
						len = sub.length();
						ans = {sub};
					} else if (sub.length() == len) {
						ans.insert(sub);
					}
				}
			}
		}

		if (ans.size() == 0) cout << "No common sequence." << endl;
		for (string a : ans) cout << a << endl;
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}