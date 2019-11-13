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

namespace SOLVE {	
	VLL readline() {
		string s;
		getline(cin,s);
		stringstream ss;
		ss << s;
		VLL A;
		ll a;
		while (ss >> a) {
			A.push_back(a);
		} 
		return A;
	}
	
	ll bs(VLL & A, ll x) {
		// returns the index of next smallest 
		// list is ascending sorted
		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L+R)/2;
			if (A[M] >= x) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		return L - 1;
	}

	ll lis(VLL & A) {
		VLL tails;
		for (ll a : A) {
			if (tails.size() == 0) {
				tails.push_back(a);
			} else if (a < tails[0]) {
				tails[0] = a;
			} else if (a > tails[tails.size() - 1]) {
				tails.push_back(a);
			} else {
				ll ind = bs(tails, a);
				tails[ind+1] = a;
			}
		}

		return tails.size();
	}

	void main() {
		ll n;
		VLL answer; // index[number] gives the order

		while (1) {
			VLL line = readline();

			if (line.size() == 0) return;
			if (line.size() == 1) {
				n = line[0];
				answer = readline();	
			} else {
				VLL student(line.size());
				// translate line to an ordered list
				REP(i,0,n) {
					student[line[i] - 1] = answer[i];
				}
				ll ans = lis(student);
				cout << ans << endl;
			}
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
