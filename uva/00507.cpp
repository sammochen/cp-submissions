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

const ll inf = 1e9+7;

namespace SOLVE {	
	void main(ll t) {
		ll n;
		cin >> n;
		VLL A(n-1);
		REP(i,0,n-1) cin >> A[i];

		ll curi = -1, curj, cur = -inf;
		ll besti, bestj, best = -inf;
		REP(i,0,n-1) {
			if (A[i] > cur + A[i]) {
				cur = A[i];
				curi = i;
				curj = i;
			} else {
				cur = cur + A[i];
				curj = i;
			}

			if (cur >= best) {
				// if cur is better OR if the length is longer
				if (cur > best || curj - curi > bestj - besti) {
					best = cur;
					besti = curi;
					bestj = curj;
				} 
				
			}
		}

		if (best <= 0) {
			cout << "Route " << t << " has no nice parts" << endl;
		} else {
			cout << "The nicest part of route " << t << " is between stops " << besti + 1 << " and " << bestj + 2 << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	// t = 1;
	cin >> t;
	REP(i,1,t+1) {
		SOLVE::main(i);
	}

	return 0;
}
