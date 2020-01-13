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
	ll value(string s, ll base) {
		ll b = 1;
		ll ans = 0;
		RREP(i, s.length() - 1, 0) {
			ll x;
			if (s[i] >= '0' && s[i] <= '9') {
				x = s[i] - '0';
			} else {
				x = s[i] - 'A' + 10;
			}
			if (x >= base) return -1;
			ans += x * b;
			b *= base;
		}
		return ans;
	}

	void main() {
		string a, b;
		while (cin >> a >> b) {
			ll done = 0;
			REP(i,2,37) {
				REP(j,2,37) {
					if (value(a,i) == value(b,j) && value(a,i) != -1) {
						printf("%s (base %lld) = %s (base %lld)\n", a.c_str(), i, b.c_str(), j);
						done = 1;
					}

					if (done) break;
				}
				if (done) break;
			}

			if (!done) {
				printf("%s is not equal to %s in any base 2..36\n", a.c_str(), b.c_str());
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
