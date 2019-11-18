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
	ll tonum(string s) {
		if (s.length() == 0) return 0;
		return (s[0] - 'A' + 1) * pow(26, s.length() - 1) + tonum(s.substr(1));
	}

	PLL convert(string s) {
		string letter, number;
		REP(i,0,s.length()) {
			if (s[i] >= '0' && s[i] <= '9') {
				letter = s.substr(0,i);
				number = s.substr(i);
				break;
			}
		}
		return  {stoll(number) - 1, tonum(letter) - 1};
	}

	ll ev(ll i, ll j, VVLL & value, vector<vector<string>> & formula) {
		string f = formula[i][j];
		if (f == "") return value[i][j];
		
		ll sum = 0;
		string part;
		f += "+"; // end it off

		for (char c : f) {
			if (c == '=') continue;
			if (c == '+') {
				PLL pos = convert(part);
				sum += ev(pos.first, pos.second, value, formula);
				part = "";
			} else {
				part += c;
			}
		}

		formula[i][j] = "";
		value[i][j] = sum;
		return sum;
	}

	void main() {
		ll m,n;
		cin >> m >> n;
		VVLL value(n, VLL(m));
		vector<vector<string>> formula(n, vector<string>(m));
		REP(i,0,n) {
			REP(j,0,m) {
				string s;
				cin >> s;
				if (s[0] == '=') formula[i][j] = s;
				else value[i][j] = stoll(s);
			}
		}

		REP(i,0,n) {
			REP(j,0,m) {
				cout << (ev(i,j,value,formula));
				if (j == m-1) cout << endl;
				else cout << ' ';
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
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
