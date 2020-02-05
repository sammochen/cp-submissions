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
struct SegTree{
    static const int maxn = 3e5 + 5;

    struct node{
        ll l,r,v;
    };

    node no[maxn*4];
    void push_up(int ind){
		no[ind].v = max(no[lson].v, no[rson].v);
    }
    void build(int l,int r,int ind, VLL & A){
        no[ind].l = l;
        no[ind].r = r;
        if(l == r) {
			no[ind].v = A[l];
        }else{
            int mid = (l+r)/2;
            build(l,mid,lson, A);
            build(mid+1,r,rson, A);
            push_up(ind);
        }
    }
    void query(int l,int r,int ind,ll& ans){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
            ans = max(ans, no[ind].v);
        }else{
            query(l,r,lson,ans);
            query(l,r,rson,ans);
            push_up(ind);
        }
    }
};

SegTree tree;
namespace SOLVE {	
	ll good(ll i, ll j, ll v) {
		ll ans = -inf;
		tree.query(i, j, 1, ans);
		if (ans <= v) return 1;
		return 0;
	}

	void main() {
		ll n; 
		cin >> n;
		VLL A(n);
		// now i record every number and its indices
		// i count streaks depending on whether they can 'see' each other
		map<ll,VLL> indices;
		set<ll> occured;
		
		REP(i,0,n) {
			cin >> A[i];
			indices[A[i]].push_back(i);
			occured.insert(A[i]);
		}
		tree.build(0, n-1, 1, A);

		ll ans = 0;
		for (ll num : occured) {
			// count streaks
			ll streak = 1;
			REP(i,1,indices[num].size()) {
				if (good(indices[num][i-1], indices[num][i], num)) {
					streak++;
				} else {
					ans += streak * (streak - 1);
					streak = 1;
				}
			}
			ans += streak * (streak - 1);
		}

		cout << ans << endl;
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
