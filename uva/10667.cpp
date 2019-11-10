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
	ll rect(VLL A) {
		ll ans = 0;
		stack<ll> ind;
		stack<ll> height;
		ind.push(-1);
		height.push(0);

		REP(i,0,A.size()) {
			ll newind = i;

			while (A[i] < height.top()) {
				ll area = (i - ind.top()) * height.top();
				ans = max(ans, area);
				newind = ind.top();
				ind.pop();
				height.pop();
			}

		
			height.push(A[i]);
			ind.push(newind);
		}

		while (height.size() > 1) {
			ll area = (A.size() - ind.top()) * height.top();
			ans = max(ans, area);
			ind.pop();
			height.pop();
		}
		return ans;
	}

	void main() {
		ll n, k;
		cin >> n >> k;

		VVLL A(n, VLL(n));

		REP(i,0,k) {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			REP(i,a-1,c) {
				REP(j,b-1,d) {
					A[i][j] = 1;
				}
			}
		}

		VLL pre(n);
		ll ans = 0;
		REP(i,0,n) {
			REP(j,0,n) {
				pre[j] = A[i][j] == 1 ? 0 : pre[j] + 1;
			}
			ans = max(ans, rect(pre));
		}

		cout << ans << endl;
	}
}


signed main() {
	ll t;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
