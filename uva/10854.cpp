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

vector<string> A;

// returns the ind, and the count
PLL count(ll start, string stop) {
	ll cnt = 1;
	ll ind = start;
	while (A[ind] != stop) {
		if (A[ind] == "S") {
			ind++;
			continue;
		}

		// has to be a "IF"
		PLL ifcount = count(ind+1, "ELSE");
		PLL elsecount = count(ifcount.first+1, "END_IF");
		ind = elsecount.first+1;
		cnt *= (ifcount.second + elsecount.second);
	}
	return {ind, cnt};
}

void solve() {
	A.clear();
	string s;
	while (cin >> s) {
		A.push_back(s);
		if (s == "ENDPROGRAM") break;
	}

	ll ans = count(0, "ENDPROGRAM").second;
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}