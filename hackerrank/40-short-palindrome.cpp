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
typedef vector<VVLL> VVVLL;
typedef vector<VVVLL> VVVVLL;

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
const ll mod = 1e9+7;

namespace SOLVE {	
	void addmod(ll & a, ll b) {
		a += b;
		a %= mod;
	}

	void main() {
		string s;
		cin >> s;

		VLL a1(26);
		VVLL a2(26, VLL(26));
		VVVLL a3(26, VVLL(26, VLL(26)));
		VVVVLL a4(26, VVVLL(26, VVLL(26, VLL(26))));
		

		REP(i,0,s.length()) {
			ll a = s[i] - 'a';
			REP(b,0,26) {
				addmod(a4[a][b][b][a], a3[a][b][b]);
				addmod(a3[b][a][a], a2[b][a]);
				addmod(a2[b][a], a1[a]);
			}
			addmod(a1[a], 1);
		}

		ll ans = 0;
		REP(i,0,26) {
			REP(j,0,26) {
				addmod(a, freq[i][j][j][i]);
			}
		}
		cout << ans << endl;
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
