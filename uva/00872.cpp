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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll allmask;
	vector<string> ans;
	VLL req;

	void dfs(string path, ll mask) {
		if (mask == allmask) ans.push_back(path);

		REP(i,0,26) {
			// if the number is not an option, continue
			if (((1LL << i) & allmask) == 0) continue;
			// if the number has appeared, continue
			if ((1LL << i) & mask) continue;
			// if not met requirement yet, continue
			if ((req[i] & mask) != req[i]) continue;

			// else, try it!
			char c = 'A' + i;
			dfs(path + c, mask | (1LL << i));
		}
	}

	ll first = 1;
	void main() {
		if (!first) cout << endl;
		first = 0;

		string s;
		getline(cin, s);
		getline(cin, s);
		
		allmask = 0;
		for (char c : s) {
			if (c != ' ') {
				allmask |= (1LL << (c - 'A'));
			}
		}

		getline(cin, s);
		stringstream ss;
		ss << s;

		req.clear();
		req.resize(26);
		while (ss >> s) {
			req[s[2] - 'A'] |= (1LL << (s[0] - 'A'));
		}

		ans.clear();
		dfs("", 0);
		
		for (string a : ans) {
			REP(i,0,a.length()) {
				cout << a[i];
				if (i != a.length() - 1) cout << ' ';
				else cout << endl;
			}
		}

		if (ans.size() == 0) {
			cout << "NO" << endl;
		}
	}
}


signed main() {
	string s;
	getline(cin, s);
	ll t = stoll(s);
	
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
