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

namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;

		db total = 0;
		vector<db> A(n); 
		REP(i,0,n) {
			cin >> A[i];
			total += A[i];
		}

		vector<db> p(1<<n); // p[mask] is chance of arriving to this config
		vector<db> E(1<<n); // E[mask] is expect turns to get to this stage
		p[0] = 1;
		E[0] = 0;

		REP(mask,0,1<<n) {
			// passing the probabilities and expected values forward

			ll stay = 0;
			REP(bit,0,n) {
				if ((1<<bit) & mask) stay += A[bit];
			}

			db stayp = 1.0 * stay / total;
			db stayE = stayp / (1.0 - stayp);
			db finishE = E[mask] + (stayE + 1.0) * p[mask];

			REP(bit,0,n) {
				ll nextmask = (1<<bit) | mask;
				if (nextmask != mask) {
					p[nextmask] += p[mask] * A[bit] / (total - stay);
					E[nextmask] += finishE * A[bit] / (total - stay);
				}
			}
		}
		
		cout << setprecision(20) << E[(1<<n) - 1] << endl;
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
