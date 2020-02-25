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

PLL eatexp(ll i);
PLL eatcomp(ll i);
PLL eatfac(ll i);

string s;
ll error;

// returns the {ind, value} of the first non-eaten bit
PLL eatexp(ll i) {
	PLL eat = eatcomp(i);
	if (error) return {-1,-1};
	if (s[eat.first] == '+') {
		PLL eatagain = eatexp(eat.first+1);
		if (error) return {-1,-1};
		return {eatagain.first, eat.second + eatagain.second};
	} else {
		return eat;
	}
}

PLL eatcomp(ll i) {
	PLL eat = eatfac(i);
	if (error) return {-1,-1};
	if (s[eat.first] == '*') {
		PLL eatagain = eatcomp(eat.first+1);
		if (error) return {-1,-1};
		return {eatagain.first, eat.second * eatagain.second};
	} else {
		return eat;
	}
}

PLL eatfac(ll i) {
	if (s[i] == '(') {
		PLL eat = eatexp(i+1);
		if (error) return {-1,-1};
		if (s[eat.first] == ')') return {eat.first + 1, eat.second};
		error = 1;
		return {-1,-1};
	} else if (s[i] >= '0' && s[i] <= '9') {
		ll value = 0;
		REP(x,i,s.length()) {
			if (s[x] < '0' || s[x] > '9') return {x, value}; 
			value *= 10;
			value += s[x] - '0';
		}
		return {s.length(), value};
	} else {
		error = 1;
		return {-1,-1};
	}
}

void solve() {
	cin >> s;
	error = 0;

	PLL ans = eatexp(0);
	if (ans.first == s.length() && error == 0) {
		cout << ans.second << endl;
	} else {
		cout << "ERROR" << endl;
	}

	
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}