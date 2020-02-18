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
	string lower(string a) {
		REP(i,0,a.size()) {
			if (a[i] <= 'Z') a[i] += ('a' - 'A');
		}
		return a;
	}
	struct driver {
		ll time;
		string s;
	};
	bool operator<(const driver & a, const driver & b) {
		if (a.time == b.time) return lower(a.s) < lower(b.s);
		return a.time < b.time;
	}
	void main() {
		ll n;
		while (cin >> n) {
			vector<driver> A(n);
			REP(i,0,n) {
				char buf[100];
				ll m, s, ms;
				ll a = scanf("%99s : %lld min %lld sec %lld ms", buf, &m, &s, &ms);
				string name = buf;
				A[i] = {ms + s * 1000 + m * 60000, name};
			}
			sort(A.begin(), A.end());

			REP(i,0,n) {
				if (i % 2 == 0) printf("Row %lld\n", i/2 + 1);
				printf("%s\n", A[i].s.c_str());
			}
			printf("\n");
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
