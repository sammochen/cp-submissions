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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
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

const ll nax = 80; // sqrt

namespace SOLVE {
	set<ll> good;
	
	// given a string s, if it is possible to split into three and form a multiplication, update the ans set
	void update(string s) {
		REP(i,0,8) { // index that this stops at
			REP(j,i+1,8) {
				ll a = stoll(s.substr(0,i+1));
				ll b = stoll(s.substr(i+1,j-i));
				ll c = stoll(s.substr(j+1));
				if (a * b == c) {
					good.insert(c); 
					// debug("found",a,b,c);
				}
			}
		}
	}
	
	void main() {
		// O(9! * 9^2)
		string s = "123456789";
		while (1) {
			update(s);
			
			next_permutation(s.begin(), s.end());
			if (s == "123456789") break;
		}
		
		ll ans = 0;
		for (ll g : good) ans += g;
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
