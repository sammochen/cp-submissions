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
	VLL p(505); 

	ll getp(ll x) {
		if (p[x] == x) return x;
		p[x] = getp(p[x]);
		return p[x];
	}

	void merge(ll a, ll b) {
		p[getp(a)] = getp(b);
	}

	ll same(ll a, ll b) {
		return getp(a) == getp(b);
	}

	struct edge {
		ll a, b;
		db w;
	};
 
	bool operator<(const edge & a, const edge & b) {
		return a.w < b.w;
	}

	void main() {
		ll S, P;
		ll read = scanf("%lld%lld", &S, &P);
		REP(i,0,P) p[i] = i;

		vector<PLL> A(P);
		REP(i,0,P) {
			read = scanf("%lld%lld", &A[i].first, &A[i].second);
		}

		vector<edge> E;

		REP(i,0,P) {
			REP(j,i+1,P) {
				db a = (A[i].first - A[j].first);
				db b = (A[i].second - A[j].second);
				db w = sqrt(a*a+b*b);
				E.push_back({i,j,w});
			}
		}

		sort(E.begin(), E.end());

		ll size = 0;
		db ans = 0;
		REP(i,0,E.size()) {
			if (same(E[i].a, E[i].b)) {
				// do nothing
			} else {
				merge(E[i].a, E[i].b);
				ans = max(ans, E[i].w);
				size++;
				if (size == P - S) {
					break;
				}
			}
		}

		printf("%.2f\n", ans);


	}
}


signed main() {
	ll t;
	ll read = scanf("%lld", &t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
