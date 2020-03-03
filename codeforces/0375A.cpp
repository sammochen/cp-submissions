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
	VLL f(string og, ll mod) {
		string s = og;
		VLL ans(mod, -1);
		do {
			ll x = stoll(s);
			ans[x%mod] = x;
			next_permutation(s.begin(), s.end());
		} while (s != og);

		return ans;
	}
	void main() {
		string s;
		cin >> s;
		// if 1,6,8,9 can make all the mod 7s, then any number before it can change to mod 7
		VLL middle = f("1689", 7); // O(4!)

		VLL freq(10);

		VLL used(10, 1); // keeps track of removing 1689
		used[1] = 0;
		used[6] = 0;
		used[8] = 0;
		used[9] = 0;

		ll m = 0;
		string start;
		string end;

		for (char c : s) {
			if (!used[c-'0']) {
				used[c - '0'] = 1;
			} else {
				if (c == '0') end.push_back(c);
				else {
					start.push_back(c);
					m *= 10;
					m += (c - '0');
					m %= 7;
				}
			}
		}

		m *= 10000;
		m %= 7;

		debug(start, end);
		string ans = start + to_string(middle[(7 - m) % 7]) + end;
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
