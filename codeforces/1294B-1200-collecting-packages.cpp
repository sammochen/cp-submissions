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
		ll n;
		cin >> n;

		VLL values;
		map<ll,PLL> point;
		values.push_back(0);
		point[0] = {0,0};

		ll ok = 1;

		REP(i,0,n) {
			ll a, b;
			cin >> a >> b;
			if (point[a+b].first + point[a+b].second != 0) {
				ok = 0;
			}
			point[a+b] = {a,b};
			values.push_back(a+b);
		}

		if (!ok) {
			cout << "NO" << endl;
			return;
		}

		sort(values.begin(), values.end());

		string ans;

		REP(i,0,n) {
			PLL p1 = point[values[i]];
			PLL p2 = point[values[i+1]];
			ll dx = p2.first - p1.first;
			ll dy = p2.second - p1.second;

			if (dx < 0 || dy < 0) {
				ok = 0;
				break;
			}
			REP(j,0,dx) ans += "R";
			REP(j,0,dy) ans += "U";
		}

		if (ok) {
			cout << "YES" << endl;
			cout << ans << endl;
		} else {
			cout << "NO" << endl;
		}

	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
