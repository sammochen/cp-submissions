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

ll zone(string s) {
	ll sign = s[0] == '+' ? 1 : -1;
	ll hour = stoll(s.substr(1,s.length() - 3));
	ll minute = stoll(s.substr(s.length() - 2));

	return sign * (hour * 60 + minute);
}


void solve() {
	ll read;
	string s, t;
	ll M, D, h, m;
	string t1, t2;
	ll timeh, timem;
	getline(cin, s);
	read = scanf("%lld %lld %lld:%lld\n", &M, &D, &h, &m);
	getline(cin, t1);
	getline(cin, t);
	getline(cin, t2);
	read = scanf("%lld:%lld", &timeh, &timem);

	ll start = h * 60 + m;
	ll finish = start + zone(t2) - zone(t1) + timeh * 60 + timem;
	start += timeh * 60 + timem;
	
	string day = finish >= 60 * 24 ? "following day" : "same day";
	finish %= (24 * 60);

	ll finishh = finish / 60;
	ll finishm = finish % 60;

	printf("Departs %s %02lld %02lld %02lld:%02lld\n", s.c_str(), M, D, h, m);
	printf("Arrives %s %02lld:%02lld %s\n", t.c_str(), finishh, finishm, day.c_str());

	read++; // just to use the read input
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}