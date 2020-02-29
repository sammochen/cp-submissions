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

// preprocess s.
// if kmp[i] == j, the length of the suffix that is also a prefix
VLL kmp(string s) {
	VLL k(s.length());
	k[0] = 0; // by definition, otherwise the whole substring is included

	ll i = 1, len = 0;
	while (i < s.length()) {
		if (s[i] == s[len]) {
			k[i] = len+1;
			i++;
			len++;
		} else {
			if (len == 0) {
				k[i] = 0;
				i++;
			} else {
				len = k[len - 1];
			}
		}
	}
	return k;
}

void solve() {
	string s;
	cin >> s;
	VLL k = kmp(s);
	string repeat = s, ans = "";

	ll rep = 0;
	REP(i,0,k.size()) {
		if (k[i] * 2 == i+1) rep = (i+1)/2;
	}
	rep = ((ll)s.length() / 2 / rep) * rep;
	repeat = s.substr(0, rep);

	ans = repeat.substr(s.length() - 2 * repeat.length());
	
	while (ans.size() < 8) ans = ans + repeat;
	cout << ans.substr(0, 8) << "..." << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}