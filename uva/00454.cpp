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
	void main() {
		ll n;
		cin >> n;
		string s;
		getline(cin, s);
		getline(cin, s);

		REP(i,0,n) {
			map<VLL, vector<string>> M;
			set<VLL> freqs;
			while (getline(cin,s)) {
				if (s == "") break;
				VLL freq(128);
				for (char c : s) {
					if (c >= '!') {
						freq[c]++;
					}
				}

				M[freq].push_back(s);
				freqs.insert(freq);
			}

			vector<string> ans;
			for (VLL freq : freqs) {
				vector<string> anagrams = M[freq];
				sort(anagrams.begin(), anagrams.end());
				REP(i,0,anagrams.size()) {
					REP(j,i+1,anagrams.size()) {
						ans.push_back(anagrams[i] + " = " + anagrams[j]);
					}
				}
			}

			sort(ans.begin(), ans.end());
			for (string s : ans) cout << s << endl;

			if (i != n-1) cout << endl;
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
