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
	struct state {
		ll id, ac, time;
		bool operator<(const state & A) {
			if (ac == A.ac) {
				if (time == A.time) {
					return id < A.id;
				}
				return time < A.time;
			}
			return ac > A.ac;
		}
	};
	
	map<ll,PLL> cur; // id -> ac, time
	map<PLL,ll> good;
	map<PLL,ll> wa;
	map<ll,ll> submit;

	ll first = 1;
	void process() {
		if (!first) printf("\n");
		first = 0;

		vector<state> A;
		REP(i,0,101) {
			if (submit[i]) {
				A.push_back({i, cur[i].first, cur[i].second});
			}
		}
		
		sort(A.begin(), A.end());
		for (state s : A) {
			printf("%lld %lld %lld\n", s.id, s.ac, s.time);
		} 
	}

	void main() {
		string s;
		getline(cin, s);
		getline(cin, s);

		while (getline(cin, s)) {
			if (s.empty()) {
				process();
				cur.clear();
				good.clear();
				submit.clear();
				wa.clear();
				continue;
			}
			stringstream ss;
			ss << s;
			ll id, problem, time;
			string status;
			
			ss >> id >> problem >> time >> status;

			if (status == "C") {
				if (!good[{id, problem}]) {
					cur[id].first++;
					cur[id].second += time + wa[{id, problem}];
					good[{id, problem}] = 1;
				}
			} else if (status == "I") {
				if (!good[{id, problem}]) wa[{id, problem}] += 20;
			}
			submit[id] = 1;
		}
		process();
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
