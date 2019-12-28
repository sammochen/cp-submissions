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
	VLL A;
	ll n, k;
	set<VLL> ans;
	void f(ll ind, ll sum, VLL all) {
		if (sum == n) {
			ans.insert(all);
		}
		if (sum > n || ind == A.size()) return;
		f(ind + 1, sum, all);
		VLL next = all;
		next.push_back(A[ind]);
		f(ind + 1, sum + A[ind], next);
	}
	void main() {
		while (in(n, k), n || k) {
			A.clear();
			A.resize(k);
			ans.clear();

			REP(i,0,k) in(A[i]);
			sort(A.rbegin(), A.rend());

			f(0,0,{});

			printf("Sums of %lld:\n", n);
			if (ans.size() == 0) {
				printf("NONE\n");
			} else {
				for (auto it = ans.rbegin(); it != ans.rend(); it++) {
					VLL a = *it;
					REP(i,0,a.size()) {
						printf("%lld", a[i]);
						if (i == a.size() - 1) printf("\n");
						else printf("+");
					}
				}
			}
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
