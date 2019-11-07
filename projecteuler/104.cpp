/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include "bigint.cpp"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bigint b) {
	stringstream ss;
	ss << b;
	string s;
	ss >> s;
	return s;
}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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
	// return true if 1-9 pandigital
	ll P(string s) {
		sort(s.begin(), s.end());
		return (s == "123456789");
	}

	void main() {
		bigint a = 1, b = 1, c;
		ll nax = 1000000;
		ll ans;

		// This takes a while!
		REP(i,3,nax) {
			c = a + b;
			a = b;
			b = c;

			string s = to_string(c);
			string front = s.substr(0,9);
			string back = s.size() < 9 ? "" : s.substr(s.size() - 9);
			//debug(front, back);
			if (P(front) && P(back)) {
				ans = i;
				break;
			}
		}

		cout << ans << endl;
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
