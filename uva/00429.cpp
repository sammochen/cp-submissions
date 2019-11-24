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
	ll diff(string a, string b) {
		if (a.length() != b.length()) return inf;
		ll cnt = 0;
		REP(i,0,a.length()) {
			cnt += a[i] != b[i] ? 1 : 0;
		}
		return cnt;
	}

	void main() {
		map<string, ll> dict;
		vector<string> D;
		string s;
		
		while (1) {
			getline(cin ,s);
			if (s == "*") break;
			D.push_back(s);
		}

		while (getline(cin, s)) {
			if (s == "") return;

			stringstream ss;
			ss << s;
			string a, b;
			ss >> a >> b;
			
			map<string, ll> d;
			map<string, ll> done;

			queue<string> q;
			q.push(a);
			done[a] = 1;
			d[a] = 0;

			while (q.size()) {
				string at = q.front();
				q.pop();
				for (string to : D) {
					if (diff(at, to) == 1 && done[to] == 0) {
						done[to] = 1;
						d[to] = d[at] + 1;
						q.push(to);
					}
				}
			}

			cout << a << ' ' << b << ' ' << d[b] << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin, s);
	REP(i,0,t) {
		SOLVE::main();
		if (i != t-1) cout << endl;
	}

	return 0;
}
