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

void solve() {
	string team1, team2;
	getline(cin, team1);
	getline(cin, team2);

	VLL scores(2);
	cin >> scores[0] >> scores[1];
	ll n;
	string s;
	cin >> n >> s;

	ll turn = 0;
	for (char c : s) {
		if (c == 'M') {
			turn = !turn;
		} else if (c == 'R') {

		} else if (c == 'C') {

		} else if (c == 'H') {
			scores[turn]++;
		} else if (c == 'P') {
			scores[turn]++;
			turn = !turn;
		}
	}

	printf("%s %lld %s %lld\n", team1.c_str(), scores[0], team2.c_str(), scores[1]);
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}