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

VLL kmp(string s) {
	ll n = s.length();
	VLL k(n);
	REP(i,1,n) {
		ll prev = k[i-1];
		while (prev && s[i] != s[prev]) {
			prev = k[prev - 1];
		}
		k[i] = prev + (s[i] == s[prev]);
	}
    return k;
}

ll look(ll shift, string & A, string & small, string & big) {
	map<char,char> m;
	REP(i,0,A.size()) {
		m[A[i]] = A[(i+shift)%A.size()];
	}

	string newsmall;
	for (char c : small) {
		newsmall.push_back(m[c]);
	}

	string total = newsmall + "#" + big;
	VLL k = kmp(total);
	ll count = 0;
	REP(i,small.size(),k.size()) {
		if (k[i] == small.size()) {
			count++;
			if (count == 2) return 0;
		}
	}
	if (count == 0) return 0;
	return 1;
}

void solve() {
	string A, small, big;
	cin >> A >> small >> big;
	
	VLL ans;
	REP(i,0,A.size()) {
		if (look(i, A, small, big)) {
			ans.push_back(i);
		}
	}

	if (ans.size() == 0) printf("no solution\n");
	else {
		if (ans.size() > 1) printf("ambiguous:");
		else printf("unique:");
		for (ll ind : ans) printf(" %lld", ind);
		printf("\n");
	}

	
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}