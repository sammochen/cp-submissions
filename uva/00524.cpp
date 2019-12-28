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
	ll n;
	VVLL ans;
	VLL p(40, -1);

	ll isp(ll x) {
		if (p[x] != -1) return p[x];
		REP(i,2,x) {
			if (x % i == 0) {
				p[x] = 0;
				return 0;
			}
		}
		p[x] = 1;
		return 1;
	}

	// mask is 1 if it still isnt done yet
	void f(VLL cur, ll mask) {
		if (mask == 0) {
			if (isp(cur[cur.size() - 1] + 1)) {
				ans.push_back(cur);
			}
			return;
		}

		REP(i,1,n+1) {
			// already done
			if (((1LL << i) & mask) == 0) continue;
			if (isp(cur[cur.size() - 1] + i) == 0) continue;

			VLL next = cur;
			next.push_back(i);
			f(next, mask ^ (1LL << i));
		}
	}

	void main() {
		ll test = 1;
		while (cin >> n) {
			if (test != 1) cout << endl;

			ans.clear();
			
			ll mask = (1LL << (n+1)) - 4;
			f({1}, mask);

			printf("Case %lld:\n", test++);
			for (VLL a : ans) {
				REP(i,0,a.size()) {
					cout << a[i];
					if (i == a.size() - 1) cout << endl;
					else cout << ' ';
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
