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

void in(string & s) {
	cin >> s;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	map<string, ll> ids;
	map<ll, string> names;
	ll id = 0;

	ll getid(string s) {
		if (ids[s] == 0) {
			id++;
			ids[s] = id;
			names[id] = s;
		}
		return ids[s] - 1;
	}

	string getname(ll id) {
		return names[id + 1];
	}

	ll test = 1;
	void main() {
		ll n, m;
		ll nax = 205;
		while (in(n), n) {
			ids.clear();
			names.clear();
			id = 0;
			VVLL d(nax, VLL(nax));
			
			REP(i,0,n) {
				ll k;
				in(k);
				VLL seq(k);
				REP(i,0,k) {
					string s;
					in(s);
					seq[i] = getid(s);
				}
				REP(i,0,k-1) {
					d[seq[i]][seq[i+1]] = 1;
				}
			}

			in(m);
			REP(i,0,m) {
				string s, t;
				in(s, t);
				d[getid(s)][getid(t)] = 1;
			}
			
			REP(i,0,id) d[i][i] = 1;

			REP(k,0,id) {
				REP(i,0,id) {
					REP(j,0,id) {
						if (d[i][k] && d[k][j]) d[i][j] = 1;
					}
				}
			}

			ll count = 0;
			string pairs = "";
			REP(i,0,id) {
				REP(j,i+1,id) {
					if (d[i][j] == 0 && d[j][i] == 0) {
						count++;
						if (count <= 2) {
							pairs += "(" + getname(i) + "," + getname(j) + ") ";
						}
					}
				}
			}

			if (pairs.size() == 0) {
				printf("Case %lld, no concurrent events.\n", test++);
			} else {
				printf("Case %lld, %lld concurrent events:\n", test++, count);
				cout << pairs << endl;	
			}	
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
