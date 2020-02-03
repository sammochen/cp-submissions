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
		VLL monsters(n);
		REP(i,0,n) cin >> monsters[i];

		ll m;
		cin >> m;
		vector<PLL> hero(m); // [power, endurance]
		REP(i,0,m) cin >> hero[i].first >> hero[i].second;

		// max hero power that can do i days
		VLL power(n+1);
		REP(i,0,m) {
			power[hero[i].second] = max(power[hero[i].second], hero[i].first);
		}
		RREP(i,n-1,0) {
			power[i] = max(power[i], power[i+1]);
		}

		ll ind = 0;
		ll ans = 0;
		while (ind < n) {
			// see how far you can go
			ll day = 0;
			ll maxpower = 0;
			while (1) {
				maxpower = max(maxpower, monsters[ind + day]);
				if (power[day+1] < maxpower) {
					break;
				}
				
				day++;
				// all the monsters
				if (ind + day == n) {
					break;
				}
			}

			// made no progress
			if (day == 0) {
				cout << -1 << endl;
				return;
			}

			ind += day;	
			ans++;		
		}

		cout << ans << endl;
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
