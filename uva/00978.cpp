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
	void main() {
		ll n, g, b;
		cin >> n >> g >> b;
		priority_queue<ll> green;
		priority_queue<ll> blue;
		REP(i,0,g) {
			ll x;
			cin >> x;
			green.push(x);
		}
		REP(i,0,b) {
			ll x;
			cin >> x;
			blue.push(x);
		}

		while (blue.size() && green.size()) {
			ll fights = min({n, (ll)blue.size(), (ll)green.size()});
			VLL results;
			REP(i,0,fights) {
				ll gwins = green.top() - blue.top();
				green.pop();
				blue.pop();
				results.push_back(gwins);
			}

			for (ll gwins : results) {
				if (gwins > 0) green.push(gwins);
				if (gwins < 0) blue.push(-gwins);
			}
		}

		if (blue.size()) {
			cout << "blue wins" << endl;
		} else if (green.size()) {
			cout << "green wins" << endl;
		} else {
			cout << "green and blue died" << endl;
		}

		while (blue.size()) {
			cout << blue.top() << endl;
			blue.pop();
		}
		while (green.size()) {
			cout << green.top() << endl;
			green.pop();
		}

	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	// t = 1;
	cin >> t;
	REP(i,1,t+1) {
		SOLVE::main();
		if (i != t) cout << endl;
	}

	return 0;
}
