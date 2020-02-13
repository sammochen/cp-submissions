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
	ll bs(VVLL & suf, ll j, ll value) {
		ll L = 0, R = suf.size() - 1;
		while (L < R) {
			ll M = (L+R) / 2;
			if (suf[M][j] <= value) {
				R = M;
			} else {
				L = M+1;
			}
		}
		return L;
	}

	void main() {
		ll n;
		string s;
		cin >> n >> s;
		string acgt = "ACGT";
		VLL A(n);
		REP(i,0,n) {
			REP(j,0,4) {
				if (acgt[j] == s[i]) {
					A[i] = j;
					break;
				}
			}
		}

		// ACGT
		VVLL suf(n+1, VLL(4));

 		RREP(i,n-1,0) {
			REP(j,0,4) {
				suf[i][j] = A[i] == j ? suf[i+1][j] + 1 : suf[i+1][j];
			}
		}

		VLL count(4, n/4);
		ll ans = n;
		REP(i,0,n+1) {
			// for every letter, see when the next best place to cut. 
			if (i != 0) {
				count[A[i-1]]--;
				if (count[A[i-1]] < 0) break;
			}

			// have to find the first suf where all values are lower than count
			ll best = i; // best case if none at all


			// for each letter, find the lowest index. find the max of these.
			REP(j,0,4) {
				ll ind = bs(suf, j, count[j]);
				best = max(best, ind);
			}
			ans = min(ans, best - i);
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
