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
	ll palindrome(ll x) {
		string a = to_string(x);
		string b = a;
		reverse(b.begin(), b.end());
		return a == b;
	}

	void main() {
		ll n = 100000000; // upper limit
		ll sqrtn = 10000; // sqrt(n)
		VLL S(sqrtn); // squares
		VLL pre(sqrtn); // prefix sum of squares - pre[i] is sum up to i
		REP(i,0,sqrtn) {
			S[i] = i*i;
		}

		REP(i,1,sqrtn) {
			pre[i] = pre[i-1] + S[i];
		}

		set<ll> nums;
		REP(i,1,sqrtn) {
			REP(j,i+1,sqrtn) { // cannot just be the square itself!
				ll sum = pre[j] - pre[i-1];
				if (sum >= n) break;
				if (palindrome(sum)) nums.insert(sum);
			}
		}

		ll ans = 0;
		for (ll num : nums) ans += num;
		cout << ans << endl;
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
