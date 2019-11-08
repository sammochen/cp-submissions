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

const ll inf = 1e9+7;

namespace SOLVE {	
	// returns the next smallest element
	ll small(VLL & A, ll x) {
		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L + R) / 2;
			if (A[M] < x) L = M + 1;
			else R = M;
		}
		return L - 1;
	}

	// returns the next largest element
	ll big(VLL & A, ll x) {
		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L + R) / 2;
			if (A[M] > x) L = M+1;
			else R = M;
		}
		return L - 1;
	}

	ll lis(VLL &A, ll start) {
		ll tailsize = 0;
		VLL tail; // size -> tail

		REP(i,start,A.size()) {
			ll size; // position to change the tail

			if (tailsize == 0) { // first element
				tailsize++;
				tail.push_back(inf);
				size = tailsize - 1;
			} else if (A[i] <= tail[0]) { // smallest element
				continue; // we HAVE to keep the first element 
			} else if (A[i] > tail[tailsize - 1]) { // largest element
				tailsize++;
				tail.push_back(inf);
				size = tailsize - 1;
			} else { 
				// find the size of next smallest element
				size = small(tail, A[i]) + 1;
			}

			tail[size] = A[i];
		}
		return tail.size();
	}

	ll lds(VLL &A, ll start) {
		ll tailsize = 0;
		VLL tail; // size -> tail

		REP(i,start,A.size()) {
			ll size; // position to change the tail

			if (tailsize == 0) { // first element
				tailsize++;
				tail.push_back(inf);
				size = tailsize - 1;
			} else if (A[i] >= tail[0]) { // largest element
				continue; // we HAVE to keep the first element 
			} else if (A[i] < tail[tailsize - 1]) { // smallest element
				tailsize++;
				tail.push_back(inf);
				size = tailsize - 1;
			} else { 
				// find the size of next largest element
				size = big(tail, A[i]) + 1;
			}

			tail[size] = A[i];
		}
		return tail.size();
	}
	
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) cin >> A[i];
		ll ans = 0;
		REP(i,0,n) {
			ans = max(ans, lis(A,i) + lds(A,i) - 1);
		}

		cout << ans << endl;
		
		
		

		
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
