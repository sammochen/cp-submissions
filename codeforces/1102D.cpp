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
	ll n;
	cin >> n;
	string s;
	cin >> s;

	VLL cnt(3);
	REP(i,0,n) {
		cnt[s[i] - '0']++;
	}

	REP(i,0,n) {
		// change to 0 if possible
		if (cnt[s[i] - '0'] > n/3 && s[i] != '0' && cnt[0] < n/3) {
			cnt[s[i] - '0']--;
			s[i] = '0';
			cnt[0]++;
		// change to 1 if its a 2
		} else if (s[i] == '2' && cnt[2] > n/3 && cnt[1] < n/3) {
			cnt[2]--;
			s[i] = '1';
			cnt[1]++;
		} 
	}

	RREP(i,n-1,0) {
		// change to 2 if possible
		if (cnt[s[i] - '0'] > n/3 && s[i] != '2' && cnt[2] < n/3) {
			cnt[s[i] - '0']--;
			s[i] = '2';
			cnt[2]++;
		// change to 1 if its a 0
		} else if (s[i] == '0' && cnt[0] > n/3 && cnt[1] < n/3) {
			cnt[0]--;
			s[i] = '1';
			cnt[1]++;
		} 
	}

	cout << s << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}