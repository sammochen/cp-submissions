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


string line() {
	string s;
	getline(cin, s);
	return s;
}

vector<string> split(string s) {
	vector<string> ans(3);
	ll ptr = 0;
	ll ind = 0;
	while (ind < s.length()) {
		if (s[ind] == ',') {
			ind+=2;
			ptr++;
		} else {
			ans[ptr].push_back(s[ind]);
			ind++;
		}
	}
	return ans;
}

void solve() {
	string name = line();
	ll n = stoll(line());

	map<string,ll> req;
	REP(i,0,n) {
		string l = line();
		vector<string> v = split(l);
		ll amount = stoll(v[2]);
		if (v[1] == "kg" || v[1] == "l") amount *= 1000;
		req[v[0]] = amount;
	}

	vector<string> bads;
	REP(i,0,n) {
		string l = line();
		vector<string> v = split(l);
		ll amount = stoll(v[2]);
		if (v[1] == "kg" || v[1] == "l") amount *= 1000;
		if (req[v[0]] > amount) {
			bads.push_back(v[0]);
		}
	}

	sort(bads.begin(), bads.end());

	if (bads.size() == 0) {
		printf("You may make your %s.\n", name.c_str());
	} else {
		printf("You may NOT make your %s.\n", name.c_str());
		printf("You need");
		REP(i,0,bads.size()) {
			printf(" %s", bads[i].c_str());
			if (i == bads.size() - 1) printf(".\n");
			else printf(",");
		}
	}



}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}