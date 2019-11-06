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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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
	void finish(VLL A) {
		REP(i,1,A.size()) {
			cout << A[i] << ' ';
		}
		cout << endl;
	}

	void main() {
		ll n;
		cin >> n;

		VLL index(n+1, -1);
		VLL A(n+1, -1);
		VLL done(n+1); // keeps track of which indices have been flipped

		REP(i,1,n+1) {
			cin >> A[i];
			index[A[i]] = i;
		}

		ll num = 1;
		ll moves = n-1;

		while (moves) {
			ll ind = index[num];
			
			// change num if it is already in good position, or it cannot be swapped (because of index)
			while ((A[ind - 1] < A[ind]) || done[ind]) {
				num++;
				if (num > n) {
					finish(A);
					return;
				}
				ind = index[num];
			}

			// swap leftwards and update A and index

			ll temp = A[ind-1];
			A[ind-1] = A[ind];
			A[ind] = temp;
			index[A[ind]] = ind;
			index[A[ind-1]] = ind-1;

			done[ind] = 1; // update index
			moves--; 
		}

		finish(A);
		return;
	}
}


signed main() {
	int t;
	// t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
