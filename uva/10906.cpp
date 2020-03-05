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

vector<string> split(string s) {
	stringstream ss;
	ss << s;
	vector<string> A;
	while (ss >> s) A.push_back(s);
	return A;
}

ll test = 1;
void solve() {
	ll n;
	cin >> n;
	getchar();
	string s;
	map<string,string> exp; // variable -> expression
	map<string,ll> saved;
	map<string,string> symbol;
	REP(i,0,n) {
		getline(cin, s);
		vector<string> splitted = split(s);
		string variable = splitted[0];
		string left = splitted[2];
		string sign = splitted[3];
		string right = splitted[4];

		// replaces variables with numbers
		string leftans = saved[left] ? exp[left] : left; 
		string rightans = saved[right] ? exp[right] : right;

		// checks cases of adding brackets
		ll leftbracket = 0, rightbracket = 0;
		if (saved[right] && symbol[right] == sign) rightbracket = 1;

		if (sign == "*" && symbol[left] == "+") leftbracket = 1;
		if (sign == "*" && symbol[right] == "+") rightbracket = 1;
		
		if (leftbracket) leftans = "(" + leftans + ")";
		if (rightbracket) rightans = "(" + rightans + ")";

		string ans = leftans + sign + rightans;
		exp[variable] = ans;
		saved[variable] = 1;
		symbol[variable] = sign;

		if (i == n-1) {
			printf("Expression #%lld: %s\n", test++, exp[splitted[0]].c_str());
		}
	}


}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}