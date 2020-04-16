#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

void solve() {
	ll n;
	cin >> n;
	// ill make a set of strings
	set<string> pos;
	REP(a,0,6) {
		REP(b,0,6) {
			REP(c,0,6) {
				REP(d,0,6) {
					string s = string(1,a + 'A') + string(1,b + 'A') + string(1,c + 'A') + string(1,d + 'A');
					pos.insert(s);
				}
			}
		}
	}

	ll firstindex = inf;
	REP(i,0,n) {
		string s;
		ll a, b;
		cin >> s >> a >> b;

		// iterate through the set 
		set<string>::iterator it = pos.begin();
		while (it != pos.end()) {
			set<string>::iterator next = it;
			next++;

			string cur = *it;

			VLL freq1(26), freq2(26);
			for (char c : s) {
				freq1[c-'A']++;
			}
			for (char c : cur) {
				freq2[c-'A']++;
			}
			ll same = 0;
			REP(i,0,26) {
				same += min(freq1[i], freq2[i]);
			}
			ll samepos = 0;
			REP(j,0,4) {
				if (s[j] == cur[j]) samepos++;
			}

			if (a != samepos || b != same-samepos) {
				pos.erase(it);
			} 
			
			it = next;
		}

		if (pos.size() == 1) {
			firstindex = min(firstindex, i);
		}
	}

	cout << *(pos.begin()) << endl;
	cout << firstindex + 1 << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}