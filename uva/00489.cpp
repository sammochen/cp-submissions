#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll solve(string a, string b) {
		map<ll,ll> ina, inb;
		string A, B;
		for (char c : a) {
			if (ina[c]) continue;
			ina[c] = 1;
			A.push_back(c);
		}
		for (char c : b) {
			if (inb[c]) continue;
			inb[c] = 1;
			B.push_back(c);
		}

		ll correct = 0, incorrect = 0;
		for (char c : B) {
			if (ina[c]) {
				correct++;
				if (correct == A.size()) return 1;
			} else {
				incorrect++;
				if (incorrect == 7) return 3;
			}
		}
		return 2;
	}
	void main() {
		ll n;
		while (cin >> n, n != -1) {
			string s, guess;
			cin >> s >> guess;
			
			ll ans = solve(s, guess);
			cout << "Round " << n << endl;
			if (ans == 1) cout << "You win." << endl;
			else if (ans == 2) cout << "You chickened out." << endl;
			else cout << "You lose." << endl;

		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
