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
	map<string, string> parent;
	map<string, ll> size;

	string getparent(string s) {
		if (parent[s] == s) return s;
		parent[s] = getparent(parent[s]);
		return parent[s];
	}

	ll getsize(string s) {
		return size[getparent(s)];
	}

	void merge(string a, string b) {
		if (getparent(a) != getparent(b)) {
			ll newsize = getsize(a) + getsize(b);
			parent[getparent(a)] = getparent(b);
			size[getparent(b)] = newsize;
		}
	}

	void init(string s) {
		if (size[s] == 0) {
			parent[s] = s;
			size[s] = 1;
		}
	}

	void main() {
		ll n;
		cin >> n;
		parent.clear();
		size.clear();
		REP(i,0,n) {
			string a, b;
			cin >> a >> b;

			init(a);
			init(b);
			merge(a,b);
			cout << getsize(a) << endl;

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
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
