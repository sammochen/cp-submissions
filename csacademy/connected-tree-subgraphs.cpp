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
template <typename A, typename B> string to_string(pair<A,B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

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

const ll mod = 1e9+7;
const ll nax = 2e5 + 5;

namespace SOLVE {	
	VLL F(nax, -1);

	ll pow(ll a, ll b) {
		if (b == 0) return 1;
		ll h = pow(a, b/2);
		ll ans = b % 2 ? h * h % mod * a : h * h;
		ans %= mod;
		return ans;
	}

	ll inv(ll x) {
		return pow(x, mod-2);
	}

	ll f(ll x) {
		if (F[x] != -1) return F[x];
		if (x == 0) return 1;
		F[x] = f(x-1) * x % mod;
		return F[x];
	}

	void addmod(ll &a, ll b) {
		a += b;
		a %= mod;
	}

	void multmod(ll &a, ll b) {
		a *= b;
		a %= mod;
	}

	void divmod(ll &a, ll b) {
		a *= inv(b);
		a %= mod;
	}

	VVLL E;
	VLL orderdp; // ways
	VLL countdp;

	void dfs(ll at, ll prev) {
		ll order = 1;
		ll count = 1;
		for (ll to : E[at]) {
			if (to != prev) {
				dfs(to, at);

				multmod(order, orderdp[to]);
				divmod(order, f(countdp[to]));

				addmod(count, countdp[to]);
			}
		}

		multmod(order, f(count-1));

		orderdp[at] = order;
		countdp[at] = count;
	}

	ll ans;

	void getans(ll at, ll prev) {
		addmod(ans, orderdp[at]);

		for (ll to : E[at]) {
			if (to != prev) {
				// switch/recalculate
				ll oldorderat = orderdp[at];
				ll oldorderto = orderdp[to];
				ll oldcountat = countdp[at];
				ll oldcountto = countdp[to];

				ll newcountat = oldcountat - oldcountto;
				ll newcountto = oldcountat;
				ll neworderat = oldorderat;
				ll neworderto = oldorderto;

				divmod(neworderat, f(oldcountat - 1));
				multmod(neworderat, f(newcountat - 1));
				multmod(neworderat, f(oldcountto));
				divmod(neworderat, oldorderto);

				divmod(neworderto, f(oldcountto - 1));
				multmod(neworderto, f(newcountto - 1));
				divmod(neworderto, f(newcountat));
				multmod(neworderto, neworderat);

				orderdp[at] = neworderat;
				orderdp[to] = neworderto;
				countdp[at] = newcountat;
				countdp[to] = newcountto;

				getans(to, at);

				orderdp[at] = oldorderat;
				orderdp[to] = oldorderto;
				countdp[at] = oldcountat;
				countdp[to] = oldcountto;
			}
		}
	}
	
	void main() {
		ll n;
		cin >> n;
		E.resize(n+1);
		countdp.resize(n+1, -1); // dp[i] is the number of ways if subtree starting at i
		orderdp.resize(n+1, -1);
		REP(i,0,n-1) {
			ll a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		ans = 0;
		dfs(1, -1);
		getans(1, -1);
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