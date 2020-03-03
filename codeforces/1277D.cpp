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
	char buf[4000005]; // note the 100 limit
	ll a = scanf("%4000004s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

namespace SOLVE {	
	void main() {
		ll n;
		in(n);
		ll zero = 0, one = 0;
		VLL onezero, zeroone;
		vector<string> A(n);
		map<string, ll> map;
		REP(i,0,n) {
			in(A[i]);
			map[A[i]] = 1;
			
			string s = A[i];
			
			if (s[0] == '0' && s[s.length() - 1] == '1') {
				zeroone.push_back(i+1);
			} else if (s[0] == '1' && s[s.length() - 1] == '0') {
				onezero.push_back(i+1);
			} else if (s[0] == '0') {
				zero++;
			} else {
				one++;
			}
		}
		
		// if there is a change and there are no 'change' ones
		if ((zero != 0 && one != 0) && (zeroone.size() + onezero.size() == 0)) {
			// not possible
			cout << -1 << endl;
			return;
		} 

		ll ok = 0;
		VLL ans;

		// we can have at most 1 more 0-1 or 1-0
		if (onezero.size() > zeroone.size()) {
			// difference / 2
			ll ansn = (onezero.size() - zeroone.size()) / 2;
			REP(i,0,onezero.size()) {
				if (ans.size() == ansn) {
					break;
				}
				string s = A[onezero[i] - 1];
				reverse(s.begin(), s.end());
				if (!map[s]) {
					ans.push_back(onezero[i]);
				}				
			}
			if (ans.size() == ansn) {
				ok = 1;
			}
		} else {
			ll ansn = (zeroone.size() - onezero.size()) / 2;
			REP(i,0,zeroone.size()) {
				if (ans.size() == ansn) {
					break;
				}
				string s = A[zeroone[i] - 1];
				reverse(s.begin(), s.end());
				if (!map[s]) {
					ans.push_back(zeroone[i]);
				}				
			}
			if (ans.size() == ansn) {
				ok = 1;
			}
		}

		if (!ok) {
			cout << -1 << endl;
			return;
		} else {
			cout << ans.size() << endl;
			for (ll x : ans) cout << x << ' ';
			cout << endl;
		}


	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
