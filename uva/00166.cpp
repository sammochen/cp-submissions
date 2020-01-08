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
	// 100 * 50 * 25 * 10 * 5 * 3
	map<VLL,ll> done;

	void main() {
		// for a given weight, see who i can put it on
		VLL maxcoins(6);
		while (1) {
			ll go = 0;
			REP(i,0,6) {
				cin >> maxcoins[i];
				if (maxcoins[i]) go = 1;
			}
			if (!go) return;

			ll d, c;
			ll x = scanf("%lld.%lld", &d, &c);
			ll m = (d*100+c) / 5;

			ll nax = 300; // arbitrary
			VLL nolimit(nax, inf);
			VLL limit(nax, inf);
			VLL coins = {1,2,4,10,20,40};
			nolimit[0] = 0;
			limit[0] = 0;
			REP(i,0,6) {
				RREP(j,nax-1,0) {
					REP(k,1,inf) {
						ll next = j + k * coins[i];
						if (next >= nax) break;
						nolimit[next] = min(nolimit[next], nolimit[j] + k);
						if (k <= maxcoins[i]) limit[next] = min(limit[next], limit[j] + k);
					}
				}
			}

			ll ans = inf;
			REP(change,0,nax) {
				if (m + change >= nax) break;
				ll amount = limit[m + change] + nolimit[change];
				ans = min(ans, amount);
			}
			printf("%3lld\n", ans);
			
			

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
