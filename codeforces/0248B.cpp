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

ll lcm(ll a, ll b) {
	return a / __gcd(a,b) * b;
}

void solve() {
	ll n;
	cin >> n;

	if (n <= 2) {
		cout << -1 << endl;
		return;
	} else if (n == 3) {
		cout << 210 << endl;
		return;
	}

	// print a 1, mod it by 21
	// with 2 digits left, thats the answer
	ll cur = 1;
	REP(i,0,n-1) {
		cur *= 10;
		cur %= 210;
	}

	ll rem = (210 - cur) % 210;
	string last = to_string(rem);
	string ans = string(n - last.length(), '0') + last;
	ans[0] = '1';

	cout << ans << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}