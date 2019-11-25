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
	map<char,char> M;

	ll p(string s) {
		REP(i,0,s.length()) {
			if (s[i] != s[s.length() - 1 - i]) return 0;
		}
		return 1;
	}

	ll m(string s) {
		REP(i,0,s.length()) {
			if (s[i] != M[s[s.length() - 1 - i]]) return 0;
		}
		return 1;
	}

	
	void main() {
		M['A'] = 'A';
		M['E'] = '3';
		M['H'] = 'H';
		M['I'] = 'I';
		M['J'] = 'L';
		M['L'] = 'J';
		M['M'] = 'M';
		M['O'] = 'O';
		M['S'] = '2';
		M['T'] = 'T';
		M['U'] = 'U';
		M['V'] = 'V';
		M['W'] = 'W';
		M['X'] = 'X';
		M['Y'] = 'Y';
		M['Z'] = '5';
		M['1'] = '1';
		M['2'] = 'S';
		M['3'] = 'E';
		M['5'] = 'Z';
		M['8'] = '8';

		string s;

		while (cin >> s) {
			ll isp = p(s);
			ll ism = m(s);

			cout << s << " -- ";
			if (isp && ism) cout << "is a mirrored palindrome." << endl;
			else if (isp) cout << "is a regular palindrome." << endl;
			else if (ism) cout << "is a mirrored string." << endl;
			else cout << "is not a palindrome." << endl;
			
			cout << endl;
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
