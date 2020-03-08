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

string upper(string s) {
	string t;
	REP(i,0,s.length()) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			t.push_back(s[i] + 'A' - 'a');
		}
	}
	return t;
}

string compress(string s) {
	string t;
	map<char,ll> done;
	for (char c : s) {
		if (done[c]) continue;
		if (c == 'Q') continue;
		done[c] = 1;
		t.push_back(c);
	}
	REP(i,0,26) {
		if (i+'A' == 'Q') continue;
		if (!done[i+'A']) t.push_back(i+'A');
	}
	return t;
}
void solve() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	a = compress(upper(a));
	b = upper(b);

	VVLL table(5, VLL(5));
	vector<PLL> pos(26);
	ll ptr = 0;
	REP(i,0,5) {
		REP(j,0,5) {
			table[i][j] = a[i*5+j] - 'A';
			pos[table[i][j]] = {i,j};
		}
	}

	string ans;
	for (ll i = 0; i < b.length(); ) {
		ll x, y;
		if (i == b.length() - 1) {
			x = b[i] - 'A';
			y = 23;
			i = b.length();
		} else if (b[i] == b[i+1]) {
			x = b[i] - 'A';
			y = 23;
			i += 1;
		} else {
			x = b[i] - 'A';
			y = b[i+1] - 'A';
			i += 2;
		}
		PLL posx = pos[x];
		PLL posy = pos[y];
		ll ansx = 0, ansy = 0;
		if (posx.first == posy.first) {
			ansx = table[posx.first][(posx.second + 1) % 5];
			ansy = table[posy.first][(posy.second + 1) % 5];
		} else if (posx.second == posy.second) {
			ansx = table[(posx.first + 1) % 5][posx.second];
			ansy = table[(posy.first + 1) % 5][posy.second];
		} else {
			ansx = table[posx.first][posy.second];
			ansy = table[posy.first][posx.second];
		}
		ans.push_back(ansx + 'A');
		ans.push_back(ansy + 'A');
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	getchar();
	REP(i,0,t) solve();
	return 0;
}