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

char toll(char c) {
	if (c == ' ') return 26;
	return c - 'A';
}

char tochar(ll x) {
	x %= 27;
	if (x == 26) return ' ';
	return x + 'A';
}

string shift(string s, ll k) {
	string t = s;
	REP(i,0,s.length()) {
		t[i] = tochar(toll(s[i]) + k);
	}
	return t;
}

vector<string> words(string s) {
	stringstream ss;
	ss << s;
	vector<string> A;
	while (ss >> s) {
		A.push_back(s);
	}
	return A;
}

void solve() {
	string s;
	map<string,ll> dict;
	while (cin >> s, s != "#") {
		dict[s] = 1;
	}

	getline(cin, s);
	getline(cin, s);

	ll cnt = -1;
	vector<string> ans;

	// shift up to 26
	REP(i,0,27) {
		string t = shift(s, i);
		vector<string> split = words(t);
		ll good = 0;
		for (string word : split) good += dict[word];

		if (good > cnt) {
			cnt = good;
			ans = split;
		}
	}

	ll count = -1;
	for (string word : ans) {
		if (count + 1 + word.length() > 60) {
			cout << endl;
			cout << word;
			count = word.length();
		} else {
			if (count != -1) cout << ' ';
			cout << word;
			count += 1 + word.length();
		}
	}
	cout << endl;




}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}