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
#define lson (ind<<1)
#define rson (ind<<1|1)
const ll nax = 100001;

namespace SOLVE {
	struct SegTree{
		static const int maxn = nax;

		struct node{
			ll l,r,v;
		};

		node no[maxn*4];
		void push_up(int ind){
			no[ind].v = max(no[lson].v, no[rson].v);
		}
		void push_down(int ind){
		}
		void build(int l,int r,int ind, VLL & A){
			no[ind].l = l;
			no[ind].r = r;
			if(l == r){
				if (l <= A.size()) no[ind].v = A[l];
				else no[ind].v = 0;
			}else{
				int mid = (l+r)/2;
				build(l,mid,lson,A);
				build(mid+1,r,rson,A);
				push_up(ind);
			}
		}
		
		void query(int l,int r,int ind,ll& ans){
			if(l>no[ind].r || r<no[ind].l)return;
			if(l<=no[ind].l && no[ind].r <= r){
				ans = max(ans, no[ind].v);
				return;
			}
			
			push_down(ind);
			query(l,r,lson,ans);
			query(l,r,rson,ans);
			push_up(ind);
		}
	};

	SegTree tree;

	ll query(ll a, ll b, VLL & A, map<ll,ll> & first, map<ll,ll> & last) {
		if (A[a] == A[b]) return b-a+1;

		ll pos1 = 0, pos2 = 0, pos3 = 0;
		if (first[A[a]] != a) {
			pos1 = last[A[a]] - a + 1;
			a = last[A[a]] + 1;
		}
		if (last[A[b]] != b) {
			pos3 = b - first[A[b]] + 1;
			b = first[A[b]] - 1; 
		}

		tree.query(a, b, 1, pos2);
		return max({pos1,pos2,pos3});
	}
	void main() {
		ll n, q;
		while (cin >> n, n) {
			cin >> q;
			VLL A(n);
			map<ll,ll> freq;
			VLL f(n);
			map<ll,ll> first, last;

			REP(i,0,n) {
				cin >> A[i];
				freq[A[i]]++;
				last[A[i]] = i;
			}
			RREP(i,n-1,0) {
				f[i] = freq[A[i]];
				first[A[i]] = i;
			}

			tree.build(0,nax-1,1,f);

			REP(i,0,q) {
				ll a, b;
				cin >> a >> b;
				ll ans = query(a-1,b-1,A,first,last);
				cout << ans << endl;
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
