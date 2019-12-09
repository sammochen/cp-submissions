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
template <typename A, typename B> string to_string(pair<A,B> p) { return to_string(p.first) + " " + to_string(p.second); }
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

const ll inf = 1e9+7;

#define y second
#define x first

namespace SOLVE {	

	// returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
	ll cw(PLL a, PLL b, PLL c) {
		ll v = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
		return v == 0 ? 0 : v < 0 ? -1 : 1;
	}

	PLL nexttop(stack<PLL> & S) {
		PLL t = S.top();
		S.pop();
		PLL nt = S.top();
		S.push(t);
		return nt;
	}

	void main() {
		ll n;
		in(n);
		vector<PLL> A;

		// first, sort them
		REP(i,0,n) {
			ll a, b;
			string c;
			in(a,b,c);
			if (c == "Y") A.push_back({a,b});
		}

		sort(A.begin(), A.end());
		debug(A);

		stack<PLL> S;
		map<PLL,ll> onstack;
		REP(i,0,A.size()) {
			while (S.size() >= 2 && cw(nexttop(S), S.top(), A[i]) == 1) {
				onstack[S.top()] = 0;
				S.pop();
			}
			if (!onstack[A[i]]) S.push(A[i]);
			onstack[A[i]]=1;
		}

		RREP(i,A.size()-2,1) {
			while (S.size() >= 2 && cw(nexttop(S), S.top(), A[i]) == 1) {
				onstack[S.top()] = 0;
				S.pop();
			}
			if (!onstack[A[i]]) S.push(A[i]);
			onstack[A[i]]=1;
		}

		stack<PLL> ans;
		while (S.size()) {
			ans.push(S.top());
			S.pop();
		}

		cout << ans.size() << endl;
		while (ans.size()) {
			cout << ans.top().x << ' ' << ans.top().y << endl;
			ans.pop();
		}

	}
}


signed main() {
	ll t;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
