/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

namespace SOLVE {	
	map<string,ll> doneoff;
	map<string,ll> doneonoff;
	map<string,ll> memooff;
	map<string,ll> memoonoff;

	ll onoff(string s);
	ll off(string s);

	ll zeros(ll x) {
		return ((1LL << x) - 1);
	}

	// makes the string 00..00
	ll off(string s) {
		if (doneoff[s]) return memooff[s];

		ll cnt = 0; // counts the ones
		ll ind = -1; // stores the first 1
		RREP(i, s.length() - 1, 0) {
			if (s[i] == '1') {
				cnt++;
				ind = ind == -1 ? i : ind;
			}
		}

		ll ans = -1;

		if (cnt == 0) ans = 0;
		else if (cnt == 1) ans = zeros(s.length() - ind);
		else if (s[0] == '0') {
			ans = off(s.substr(1));
		} else {
			ans = onoff(s.substr(1)) + 1 + zeros(s.length() - 1);
		}

		doneoff[s] = 1;
		memooff[s] = ans;
		return ans;
	}

	// makes the string 10..00
	ll onoff(string s) {
		if (doneonoff[s]) return memoonoff[s];

		ll ans = -1;
		if (s.length() == 0) {
			ans = 0;
		} else if (s[0] == '1') {
			ans = off(s.substr(1));
		} else {
			ans = onoff(s.substr(1)) + 1 + zeros(s.length() - 1);
		}

		doneonoff[s] = 1;
		memoonoff[s] = ans;
		return ans;
	}

	void main() {
		string s;
		cin >> s;

		ll ans = off(s);

		cout << ans << endl;
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
