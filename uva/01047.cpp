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
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll test = 1;
	void main() {
		ll n, m;
		while (cin >> n >> m, n || m) {
			VLL A(n);
			REP(i,0,n) cin >> A[n - 1 - i];
			ll k;
			cin >> k;
			vector<PLL> common(k);

			REP(i,0,k) {
				ll x;
				cin >> x;
				ll mask = 0;
				REP(j,0,x) {
					ll y;
					cin >> y;
					y = n - y;
					mask |= (1LL << y);
				}
				ll v;
				cin >> v;
				common[i] = {mask, v};
			}

			VLL value(1LL << n);
			// going up by bitmask
			REP(mask, 0, (1LL << n)) {
				// i can add a bit if it is not included already
				REP(bit,0,n) {
					ll next = mask | (1LL << bit);
					if (mask == next) continue;
					ll v = A[bit];
					// substract any that is already included
					for (PLL c : common) {
						if ((1LL << bit) & c.first) {
							if (mask & c.first) {
								v -= c.second;
							}
						}
					}

					value[next] = value[mask] + v;
				}
			}

			ll ans = 0;
			ll ansmask;
			REP(i,0,(1LL << n)) {
				ll count = 0;
				REP(j,0,n) {
					if ((1LL << j) & i) count++;
				}
				if (count == m) {
					if (value[i] >= ans) {
						ans = value[i];
						ansmask = i;
					}
				}
			}


			printf("Case Number  %lld\n", test++);
			printf("Number of Customers: %lld\n", ans);
			printf("Locations recommended:");
			RREP(i,n-1,0) {
				if ((1LL << i) & ansmask) printf(" %lld", n - i);
			}
			printf("\n\n");

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
