#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll test = 1;
	void main() {
		string s;
		cin >> s;
		ll n = s.length();
		ll buf = 100;
		vector<string> ans(buf*2, string(n+1, ' '));
		ll cur = 0;
		map<ll,ll> done;
		map<ll,ll> last;
		REP(i,0,s.length()) {
			if (s[i] == 'R') {
				ans[buf+cur][i] = '/';
				done[buf+cur] = 1;
				last[buf+cur] = i;
				cur++;
			} else if (s[i] == 'F') {
				ans[buf+cur-1][i] = '\\';
				done[buf+cur-1] = 1;
				last[buf+cur-1] = i;
				cur--;
			} else {
				ans[buf+cur][i] = '_';
				done[buf+cur] = 1;
				last[buf+cur] = i;
			}
		}

		printf("Case #%lld:\n", test++);

		RREP(i,buf*2-1,0) {
			if (done[i]) {
				cout << "| ";
				REP(j,0,n) {
					if (j > last[i]) break;
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
		cout << "+-" << string(ans[0].size(), '-') << endl;
		cout << endl;
	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
