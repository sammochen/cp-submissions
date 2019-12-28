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
	void main() {
		set<ll> nums = {0, 50}; // miss, bullseye
		REP(i,1,21) {
			nums.insert(i);
			nums.insert(2*i);
			nums.insert(3*i);
		}
		VLL A;
		for (ll x : nums) A.push_back(x);

		ll n = A.size();
		

		ll goal;
		while (cin >> goal, goal > 0) {
			set<VLL> cs;
			set<VLL> ps;
			REP(i,0,n) {
				REP(j,0,n) {
					REP(k,0,n) {
						if (A[i] + A[j] + A[k] != goal) continue;

						VLL c = {i,j,k};
						VLL p = {i,j,k};

						sort(c.begin(), c.end());
						cs.insert(c);
						ps.insert(p);
					}
				}
			}

			if (cs.size() == 0) {
				printf("THE SCORE OF %lld CANNOT BE MADE WITH THREE DARTS.\n", goal);
			} else {
				printf("NUMBER OF COMBINATIONS THAT SCORES %lld IS %lld.\n", goal, (ll)cs.size());
				printf("NUMBER OF PERMUTATIONS THAT SCORES %lld IS %lld.\n", goal, (ll)ps.size());
			}
			printf("**********************************************************************\n");
		}

		printf("END OF OUTPUT\n");
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
