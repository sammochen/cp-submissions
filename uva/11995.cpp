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
		ll n;
		while (cin >> n) {
			queue<ll> q;
			stack<ll> s;
			priority_queue<ll> pq;

			VLL ok(3, 1);
			REP(i,0,n) {
				ll a, b;
				cin >> a >> b;

				if (a == 1) {
					if (ok[0]) q.push(b);
					if (ok[1]) s.push(b);
					if (ok[2]) pq.push(b);
				} else {
					if (ok[0]) {
						if (q.size() == 0) ok[0] = 0;
						else if (q.front() != b) ok[0] = 0;
					}
					if (ok[1]) {
						if (s.size() == 0) ok[1] = 0;
						else if (s.top() != b) ok[1] = 0;
					}
					if (ok[2]) {
						if (pq.size() == 0) ok[2] = 0;
						else if (pq.top() != b) ok[2] = 0;
					}

					if (ok[0]) q.pop();
					if (ok[1]) s.pop();
					if (ok[2]) pq.pop();
				}
			}

			if (ok[0] + ok[1] + ok[2] > 1) {
				cout << "not sure" << endl;
			} else if (ok[0] + ok[1] + ok[2] == 0) {
				cout << "impossible" << endl;
			} else if (ok[0]) {
				cout << "queue" << endl;
			} else if (ok[1]) {
				cout << "stack" << endl;
			} else {
				cout << "priority queue" << endl;
			}
		}
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
