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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	ll cur = 0;
	ll bits = 0;
	vector<PLL> ans;
	REP(i,0,n) {
		// first, make it balanced. if i ever go into negative, reverse with the first opposite i see
		if (cur == 0 && s[i] == ')') {
			REP(j,i+1,n) {
				if (s[j] == '(') {
					ans.push_back({i, j});
					reverse(s.begin() + i, s.begin() + j + 1);
					break;
				}
			}
		}
		if (cur == 1 && s[i] == '(') {
			REP(j,i+1,n) {
				if (s[j] == ')') {
					ans.push_back({i, j});
					reverse(s.begin() + i, s.begin() + j + 1);
					break;
				}
			}
		}

		if (s[i] == '(') cur++;
		else {
			cur--;
			if (cur == 0) bits++;
		}
	}

	// then, i make bits the same if it has more
	while (bits > k) {
		cur = 0;
		REP(i,0,n) {
			if (cur == 1 && s[i] == ')') {
				ans.push_back({i, i+1});
				reverse(s.begin() + i, s.begin() + i + 2);
				bits--;
				if (bits == k) break;
			}
			if (s[i] == '(') cur++;
			else cur--;
		}
	}
	
	cout << ans.size() << endl;
	for (PLL a : ans) cout << a.first+1 << ' ' << a.second+1 << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}