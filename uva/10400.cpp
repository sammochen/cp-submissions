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

const string inv = "NO EXPRESSION";
const ll nax = 32000;
namespace SOLVE {	
	VVLL dp;
	VLL A;

	ll inrange(ll k) {
		return (k > -nax && k < nax);
	}

	// returns 1 or 0 for possible or not
	ll get(ll i, ll k) {
		if (i < 0) return 0;
		if (i == 0) return (k == A[0]) ? 1 : 0;
		if (!inrange(k)) return 0;

		if (dp[i][k+nax-1] != -1) return dp[i][k+nax-1];
		
		

		ll plus = get(i-1,k-A[i]);
		ll minus = get(i-1,k+A[i]);
		ll mult = (A[i] != 0 && k % A[i] == 0) ? get(i-1,k/A[i]) : 0;
		ll div = get(i-1,k*A[i]);	
		ll ans = plus | minus | mult | div;

		dp[i][k+nax-1] = ans;
		return ans;
	}

	

	void main() {
		ll n;
		cin >> n;

		A.resize(n);
		REP(i,0,n) cin >> A[i];

		dp.clear();
		dp.resize(n, VLL(nax*2, -1));

		ll k;
		cin >> k;

		ll possible = get(A.size() - 1, k);
		
		if (!possible) {
			cout << inv << endl;
			return;
		} 

		ll cur = A[0];
		cout << A[0];
		REP(i,1,n) {
			if (inrange(cur+A[i]) && dp[i][cur+A[i] +nax-1] == 1) {
				cout << "+";
				cur += A[i];
			} else if (inrange(cur-A[i]) && dp[i][cur-A[i] +nax-1] == 1) {
				cout << "-";
				cur -= A[i];
			} else if (inrange(cur*A[i]) && dp[i][cur*A[i] +nax-1] == 1) {
				cout << "*";
				cur *= A[i];
			} else if (inrange(cur/A[i]) && dp[i][cur/A[i] +nax-1] == 1) {
				cout << "/";
				cur /= A[i];
			} else {
				debug("Weird");
				exit(1);
			}
			cout << A[i];
		}

		cout << "=" << to_string(k) << endl;

	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
