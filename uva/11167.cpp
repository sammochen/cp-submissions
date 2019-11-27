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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

const ll inf = (ll)1e18 + 5;
const ll source = -1000000;
const ll sink = 1000000;

namespace SOLVE {	
	void addedge(ll at, ll to, ll w, map<ll,set<ll>> & E, map<PLL, ll> & W) {
		E[at].insert(to);
		E[to].insert(at);
		W[{at, to}] = w;
	}

	// O(n*)
	ll edmondskarp(map<ll,set<ll>> & E, map<PLL, ll> & W) {
		ll mf = 0;
		while (1) {
			// bfs!!!!! again!
			map<ll,ll> visited;
			map<ll,ll> parent;
			queue<PLL> Q;

			visited[source] = 1;
			Q.push({source,inf});
			ll ok = 0;
			ll f;
			while (Q.size()) {
				PLL at = Q.front();
				Q.pop();

				for (ll to : E[at.first]) {
					if (!visited[to] && W[{at.first,to}] > 0) {
						visited[to] = 1;
						Q.push({to, min(W[{at.first, to}], at.second)});
						parent[to] = at.first;

						if (to == sink) {
							ok = 1;
							f = min(W[{at.first, to}], at.second);
							break;
						}
					}
				}
				if (ok) break;
			}

			if (!ok) break;

			mf += f;
			for (ll x = sink; x != source; x = parent[x]) {
				ll p = parent[x];
				W[{p,x}] -= f;
				W[{x,p}] += f;
			}
		}
		return mf;
	}

	ll getm(ll x) {
		return -x-1;
	}

	ll geti(ll x) {
		return x+1;
	}

	void main() {
		ll t = 1;
		while(1) {
			ll n, m, target = 0;
			scanf("%lld", &n);
			if (n == 0) return;
			scanf("%lld", &m);

			// first, grab all the monkeys, and note all the start and ending times
			vector<PLL> I(n);
			set<ll> timeset; // notes all the times mentioned (to break the time intervals)

			// i will use adjlist to reduce memory
			map<ll, set<ll>> E;
			map<PLL, ll> W;

			REP(i,0,n) {
				ll v;
				scanf("%lld%lld%lld", &v, &I[i].first, &I[i].second);
				timeset.insert(I[i].first);
				timeset.insert(I[i].second);
				target += v;
				
				// add edges between source and monkey
				addedge(source,getm(i),v,E,W);
			}

			VLL times; // easier to access
			for (ll time : timeset) times.push_back(time);

			// add edges between interval and sink
			REP(j,0,times.size()-1) {
				addedge(geti(j),sink,m*(times[j+1] - times[j]),E,W);
			}
	
			// add edges between monkey and interval
			REP(i,0,n) {
				REP(j,0,times.size()-1) {
					if (I[i].first <= times[j] && times[j+1] <= I[i].second) {
						addedge(getm(i),geti(j),times[j+1]-times[j],E,W);
					}
				}
			}

			// edmond karps
			ll mf = edmondskarp(E, W);

			if (mf == target) {
				printf("Case %lld: Yes\n", t++);
				
				map<ll,ll> freq; // max m
				VLL starts(times.size()); // keep track of recently used time interval

				REP(i,0,n) {
					vector<PLL> P, ansP; // periods, collapsed periods
					
					REP(j,0,times.size()) {
						ll w = W[{geti(j), getm(i)}];
						while (w > 0) {
							ll end = min(times[j] + starts[j] + w, times[j+1]);
							P.push_back({times[j] + starts[j], end});
							
							ll added = (end - (times[j] + starts[j]));

							starts[j] += added;
							starts[j] %= (times[j+1] - times[j]);
							w -= added;
						}				
					}
					sort(P.begin(), P.end());
					ll one = -1, two = -1;
					REP(i,0,P.size()) {
						if (P[i].first == two) {
							two = P[i].second;
						} else {
							if (one != -1) ansP.push_back({one, two});
							one = P[i].first;
							two = P[i].second;
						}
					}
					if (one != -1) ansP.push_back({one, two});
					
					printf("%lld", (ll)ansP.size());
					for (PLL x : ansP) {
						printf(" (%lld,%lld)", x.first, x.second);
					}
					cout << endl;
				}
			
			} else {
				printf("Case %lld: No\n", t++);
			}
		}
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
