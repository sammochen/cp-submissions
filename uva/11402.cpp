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
const ll nax = 1024001;
#define lson (ind<<1)
#define rson (ind<<1|1)

struct SegTree{
    static const int maxn = nax;
    struct node{
        int l,r,v,lazy;
    };

    node no[maxn*4];
	ll range(ll ind) {
		return no[ind].r - no[ind].l + 1;
	}

	ll value(ll ind) {
		if (no[ind].lazy == 0) return no[ind].v;
		if (no[ind].lazy == 1) return 0;
		if (no[ind].lazy == 2) return range(ind);
		if (no[ind].lazy == 3) return range(ind) - no[ind].v;
		return -inf;
	}

	ll fliplazy(ll x) {
		if (x == 0) return 3;
		if (x == 3) return 0;
		if (x == 1) return 2;
		if (x == 2) return 1;
	}

    void push_up(int ind){
		no[ind].v = value(lson) + value(rson);
	}

    void push_down(int ind){
		if (no[ind].lazy) {
			// 1: clear, 2: set, 3: flip
			if (no[ind].lazy == 1) {
				no[ind].v = 0;

				no[lson].lazy = 1;
				no[rson].lazy = 1;
			} else if (no[ind].lazy == 2) {
				no[ind].v = range(ind);

				no[lson].lazy = 2;
				no[rson].lazy = 2;
			} else if (no[ind].lazy == 3) {
				no[ind].v = range(ind) - no[ind].v;

				no[lson].lazy = fliplazy(no[lson].lazy);
				no[rson].lazy = fliplazy(no[rson].lazy);
			}
			
			no[ind].lazy = 0;
		}
    }
    void build(int l,int r,int ind,string & s){
		no[ind].lazy = 0;
		no[ind].v = 0;
        no[ind].l = l;
        no[ind].r = r;
        if(l == r){
			no[ind].v = s[l] - '0';
        }else{
            int mid = (l+r)/2;
            build(l,mid,lson,s);
            build(mid+1,r,rson,s);
            push_up(ind);
        }
    }
	// 1 to clear, 2 to set, 3 to flip
    void update(int l,int r,int ind,int val){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r) {
			// clear
			if (val == 1) {
				no[ind].lazy = 1;
			// set
			} else if (val == 2) {
				no[ind].lazy = 2;
			// flip
			} else if (val == 3) {
				no[ind].lazy = fliplazy(no[ind].lazy);
			}
        }else{
            push_down(ind);
            update(l,r,lson,val);
            update(l,r,rson,val);
            push_up(ind);
        }
    }
    void query(int l,int r,int ind,ll& ans){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){   
			ans += value(ind);
        }else{
            push_down(ind);
            query(l,r,lson,ans);
            query(l,r,rson,ans);
            push_up(ind);
        }
    }
};

SegTree tree;

namespace SOLVE {	
	ll test = 1;
	void main() {
		printf("Case %lld:\n", test++);

		ll m;
		in(m);
		string s;
		REP(i,0,m) {
			ll f;
			string t;
			in(f,t);
			REP(j,0,f) s += t;
		}

		tree.build(0,s.length() - 1,1,s);
		ll q;
		in(q);
		ll query = 1;
		REP(i,0,q) {
			string command;
			ll a, b;
			in(command, a, b);
			if (command == "F") tree.update(a, b, 1, 2);
			if (command == "E") tree.update(a, b, 1, 1);
			if (command == "I") tree.update(a, b, 1, 3);
			if (command == "S") {
				ll ans = 0;
				tree.query(a, b, 1, ans);
				printf("Q%lld: %lld\n", query++, ans);
			}
		}
	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
