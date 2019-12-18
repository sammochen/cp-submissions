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

#include <bits/stdc++.h>

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<db> VDB;
typedef vector<VDB> VVDB;

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

void in(double & x) {
	ll a = scanf("%lf", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;


namespace SOLVE {	
	void rowflip(VVDB & A, ll i, ll j) {
		VDB temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	void rowmult(VVDB & A, ll i, db k) {
		REP(j,0,A.size()) {
			A[i][j] *= k;
		}
	}

	void rowaddmult(VVDB & A, ll i, ll j, db k) {
		REP(x,0,A.size()) {
			A[i][x] += k * A[j][x];
		}
	}

	VVDB identity(ll n) {
		VVDB A(n, VDB(n));
		REP(i,0,n) {
			A[i][i] = 1;
		}
		return A;
	}

	VVDB inverse(VVDB A) {
		ll n = A.size();
		VVDB I = identity(n);

		REP(p,0,n) {
			REP(x,p,n) {
				if (A[x][p] != 0) {
					rowflip(I, x, p);
					rowflip(A, x, p);
					break;
				}
			}

			rowmult(I, p, 1 / A[p][p]);
			rowmult(A, p, 1 / A[p][p]);

			REP(r,0,n) {
				if (r == p) continue;

				rowaddmult(I, r, p, -A[r][p]);
				rowaddmult(A, r, p, -A[r][p]);
			}
			
		}
		return I;
	}

	VVDB operator*(VVDB a, VVDB b) {
		VVDB c(a.size(), VDB(b[0].size()));
		
		REP(i,0,a.size()) {
			REP(j,0,a[0].size()) {
				REP(k,0,b[0].size()) {
					c[i][k] += a[i][j] * b[j][k];
				}
			}
		}
		
		return c;			
	}

	// needed for precision
	unsigned long long llpow(unsigned long long a, unsigned long long b) {
		if (b == 0) return 1;
		unsigned long long c = llpow(a, b/2);
		c = c * c;
		if (b%2) c *= a;
		return c;
	}

	void main() {
		VVDB M(7, VDB(7));
		REP(i,0,7) {
			REP(j,0,7) {
				M[i][j] = pow(i+1,j);
			}
		}

		M = inverse(M);

		ll t;
		in(t);
		REP(i,0,t) {
			vector<unsigned long long> goal(1500);
			REP(i,0,1500)  cin >> goal[i];

			// choose the first 7
			VVDB X(7, VDB(1));
			REP(i,0,7) {
				X[i][0] = goal[i];
			}

			// solve it
			VVDB ans = M * X;

			ll good = 1;

			// convert it back to long long
			vector<unsigned long long> bigans(7);
			REP(i,0,7) {
				ll x = round(ans[i][0]);
				if (x < 0 || x > 1000) {
					good = 0;
					break;
				}
				bigans[i] = x;
			}

			// check it against all 1500
			for (int i = 0; i < 1500 && good; i++) {
				unsigned long long sum = 0;
				db dsum = 0;
				REP(j,0,7) {
					 // do it with double first to check overflow
					dsum = dsum + ((db)bigans[j] * pow(i+1, j));
					if (dsum > ULONG_LONG_MAX) {
						good = 0;
						break;
					}
					// then do it with ull
					sum = sum + (bigans[j] * llpow(i+1, j));
				}
			
				if (good && sum != goal[i]) {
					good = 0;
					break;
				}
			}

			if (good) {
				REP(i,0,7) {
					cout << bigans[i];
					if (i == 6) cout << endl;
					else cout << ' ' ;
				}
			} else {
				printf("This is a smart sequence!\n");
			}
		}

	}
}


signed main() {
	SOLVE::main();
	return 0;
}
