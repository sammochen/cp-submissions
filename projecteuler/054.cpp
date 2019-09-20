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
template <typename A> string to_string(pair<A,A> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
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

#define V first
#define S second

namespace SOLVE {
	// high 1
	// pair 2
	// 2pair 3
	// triple 4
	// straight 5
	// flush 6
	// fullhouse 7
	// fours 8
	// straightflush 9

	ll straight(vector<PLL> hand) {
		// remembering 0 1 2 3 12 case
		if (hand[4].V == 12 && hand[3].V == 3) {
			hand[4].V = -1;
			sort(hand.begin(), hand.end());
		}

		REP(i,0,4) {
			if (hand[i].V + 1 != hand[i+1].V) return 0;
		}

		return hand[4].V;
	}

	ll flush(vector<PLL> hand) {
		REP(i,1,5) {
			if (hand[i].S != hand[0].S) return 0;
		}
		return 1;
	}

	VVLL freq(vector<PLL> hand) {
		VLL f(13);
		for (PLL card : hand) {
			f[card.V]++;
		}
		VVLL ff(5); // ff[2] gives the numbers that come up twice

		REP(i,0,13) {
			ff[f[i]].push_back(i);
		}
		return ff;
	}

	VLL score(vector<PLL> hand) {
		VVLL ff = freq(hand);
		ll str = straight(hand);
		ll fl = flush(hand);
		
		if (str && fl) return VLL{9,str};
		if (ff[4].size()) return VLL{8, ff[4][0]};
		if (ff[3].size() && ff[2].size()) return VLL{7, ff[3][0]};
		if (fl) return VLL{6, hand[4].V, hand[3].V, hand[2].V, hand[1].V, hand[0].V};
		if (str) return VLL{5, str};
		if (ff[3].size()) return VLL{4, ff[3][0], ff[1][1], ff[1][0]};
		if (ff[2].size() == 2) return VLL{3, ff[2][1], ff[2][0], ff[1][0]};
		if (ff[2].size() == 1) return VLL{2, ff[2][0], ff[1][2], ff[1][1], ff[1][0]};
		return VLL{1, ff[1][4], ff[1][3], ff[1][2], ff[1][1], ff[1][0]};
	}

	ll winner(vector<PLL> a, vector<PLL> b) {
		VLL sa = score(a);
		VLL sb = score(b);
		
		debug(sa);
		
		ll n = min(sa.size(), sb.size());
		REP(i,0,n) {
			if (sa[i] > sb[i]) return 0;
			if (sa[i] < sb[i]) return 1;
		}
		return -1;
	}
	
	ll value(char c) {
		if (c == 'A') return 12;
		if (c == 'K') return 11;
		if (c == 'Q') return 10;
		if (c == 'J') return 9;
		if (c == 'T') return 8;
		return c - '2';
	}
	
	ll suit(char c) {
		if (c == 'D') return 3;
		if (c == 'S') return 2;
		if (c == 'H') return 1;
		if (c == 'C') return 0;
	}

	void main() {
		ll ans = 0;
		string s;
		
		REP(i,0,1000) {
			vector<PLL> p1, p2;
			
			REP(i,0,5) {
				cin >> s;
				p1.push_back(MP(value(s[0]), suit(s[1])));
			}
			
			REP(i,0,5) {
				cin >> s;
				p2.push_back(MP(value(s[0]), suit(s[1])));
			}
			
			sort(p1.begin(), p1.end());
			sort(p2.begin(), p2.end());
			
			ll w = winner(p1,p2);
			ans += (w == 0);
		}
		
		cout << ans << endl;

	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
