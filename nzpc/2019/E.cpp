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
	VLL A(5);
	REP(i,0,5) cin >> A[i];

	ll S;
	cin >> S;
	vector<string> students(S);
	map<string,string> id;
	REP(i,0,S) {
		string x, first, second;
		cin >> x >> first >> second;
		students[i] = first + " " + second;
		id[students[i]] = x;
	}

	map<string, map<string,ll>> count; // count[id][exercise]
	map<string,ll> score;

	string a, b, c;
	while (cin >> a >> b >> c, a != "0") {
		count[a][b]++;
		if (c == "P") {
			if (count[a][b] == 1) {
				score[a] += 10 * A[b[0] - 'A'];
			} else if (count[a][b] == 2) {
				score[a] += 7 * A[b[0] - 'A'];
			} else {
				score[a] += 4 * A[b[0] - 'A'];
			}
		}
	}

	ll total = 0;
	REP(i,0,5) total += A[i] * 10;

	for (string name : students) {
		string pass = (score[id[name]] * 2 >= total) ? "Pass" : "Fail";
		printf("%s %s\n", name.c_str(), pass.c_str());
	}

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}