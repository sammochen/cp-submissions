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

string s;

pair<ll,db> smeech(ll ind) {
	if (s[ind] == '(') {
		pair<ll,db> p = smeech(ind+1);
		pair<ll,db> smeech1 = smeech(p.first + 1);
		pair<ll,db> smeech2 = smeech(smeech1.first + 1);
		return {smeech2.first + 1, p.second * (smeech1.second + smeech2.second) + (1 - p.second) * (smeech1.second - smeech2.second)};
	} else { // its a number
		db num = 0;
		db deci = 1;
		ll sign = 1;
		while (('0' <= s[ind] && s[ind] <= '9') || s[ind] == '.' || s[ind] == '-') {
			if (s[ind] == '-') {
				sign = -1;
			} else if (s[ind] == '.') {
				deci = 0.1;
			} else if (deci == 1) {
				num *= 10;
				num += (s[ind] - '0');
			} else {
				num += deci * (s[ind] - '0');
				deci /= 10.0;
			}
			ind++;
		}
		return {ind, num * sign};
	}
}

void solve() {
	while (getline(cin, s), s != "()") {
		db ans = smeech(0).second;
		printf("%.2f\n", ans);
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}