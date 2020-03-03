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
template <typename A> string to_string(multiset<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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
	void main() {
		ll n, k;
		cin >> n >> k;
		VLL need(n);
		REP(i,0,n) cin >> need[i];
		
		ll one;
		cin >> one;
		
		VLL cost(n);
		REP(i,0,n) cin >> cost[i];	
		
		REP(i,0,n) {
			need[i] -= k;
			need[i] = max(need[i], 0LL);
			need[i] = need[i] % one == 0 ? need[i] / one : need[i] / one + 1;
		}
		
		// debug(need);
		
		ll count = 0;
		ll ans = 0;
		priority_queue<ll, VLL, greater<ll>> pq;
		
		REP(i,0,n) {
			pq.push(cost[i]);
			
			while (need[i] > count) {
				if (pq.size() == 0) {
					cout << -1 << endl;
					exit(0);
				}
				ans += pq.top();
				pq.pop();
				count++;
			}
		}
		
		cout << ans << endl;
				
	
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
