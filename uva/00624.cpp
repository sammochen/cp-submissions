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
	VLL ans;

	// return max number under limit
	ll get(VLL & A, ll ind, ll limit) {
		if (limit < 0) return -inf;
		if (ind == A.size()) return 0;

		ll pos1 = get(A, ind+1, limit - A[ind]) + A[ind];
		ll pos2 = get(A, ind+1, limit);

		return max(pos1, pos2);
	}

	void print(VLL & A, ll ind, ll limit) {
		if (ind == A.size()) return;

		ll pos1 = get(A, ind+1, limit - A[ind]) + A[ind];
		ll pos2 = get(A, ind+1, limit);

		if (pos1 >= pos2) {
			ans.push_back(A[ind]);
			print(A, ind+1, limit - A[ind]);
		} else {
			print(A, ind+1, limit);
		}
	}

	void main() {
		string s;
		while (getline(cin, s)) {
			stringstream ss;
			ss << s;
			ll k, n;
			ss >> k >> n;
			VLL A(n);
			REP(i,0,n) ss >> A[i];

			ans.clear();
			print(A, 0, k);
			REP(i,0,ans.size()) cout << ans[i] << ' ';
			cout << "sum:" << get(A, 0, k) << endl;
			
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
