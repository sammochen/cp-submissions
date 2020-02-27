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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

char get(ll i, ll j, ll n) {
	i %= (2*n-1);
	j %= (2*n-1);
	if (i >= n) i = 2*n-2-i;
	if (j >= n) j = 2*n-2-j;

	if (i + j < n-1) return '.';
	ll value = n-1-i+n-1-j;
	value %= 26;
	return ('a'+value);

}

void solve() {
	ll n, r1, c1, r2, c2;
	ll test = 1;
	while (cin >> n, n) {
		cin >> r1 >> c1 >> r2 >> c2;
		debug(r1,r2,c1,c2);

		printf("Case %lld:\n", test++);
		REP(i,r1,r2+1) {
			REP(j,c1,c2+1) {
				printf("%c", get(i,j,n));
			}
			cout << endl;
		}		
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}