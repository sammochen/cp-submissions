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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

char other(char a, char b) {
	if (a == b) return a;
	vector<string> p = {"123", "RGB", "FSE", "DOS"};
	for (string pp : p) {
		ll count = 0;
		for (char c : pp) {
			if (c == a || c == b) count++;
		}
		if (count == 2) {
			for (char c : pp) {
				if (c != a && c != b) return c;
			}
		}
	}
	return '?';
}
void solve() {
	ll n;
	cin >> n;
	REP(i,0,n) {
		string s, t;
		cin >> s >> t;

		string ans;
		REP(i,0,s.length()) {
			ans.push_back(other(s[i], t[i]));
		}
		cout << ans << endl;

	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}