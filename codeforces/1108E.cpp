#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

#define lson (ind<<1)
#define rson (ind<<1|1)

struct SegTree{
    static const ll maxn = 1e5+5;

    struct node{
        ll l,r,v,lazy,lazyv;
    };

    node no[maxn*4];

    void push_up(ll ind){
		no[ind].v = max(no[lson].v, no[rson].v);
    }
    void push_down(ll ind){
		if (no[ind].lazy) {
			no[lson].lazy = 1;
			no[rson].lazy = 1;
			no[lson].v += no[ind].lazyv;
			no[rson].v += no[ind].lazyv;
			no[lson].lazyv += no[ind].lazyv;
			no[rson].lazyv += no[ind].lazyv;

			no[ind].lazy = 0;
			no[ind].lazyv = 0;
		}
    }
    void build(ll l, ll r, ll ind, VLL & A){
        no[ind].l = l;
        no[ind].r = r;
        if(l == r){
			no[ind].v = A[l];
        }else{
            ll mid = (l+r)/2;
            build(l,mid,lson,A);
            build(mid+1,r,rson,A);
            push_up(ind);
        }
    }
    void update(ll l, ll r, ll ind, ll val){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
			no[ind].v += val;
			no[ind].lazy = 1;
			no[ind].lazyv += val;
        }else{
            push_down(ind);
            update(l,r,lson,val);
            update(l,r,rson,val);
            push_up(ind);
        }
    }
    void query(ll l, ll r, ll ind, ll & ans){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
            ans = no[ind].v;
        }else{
            push_down(ind);
            query(l,r,lson,ans);
            query(l,r,rson,ans);
            push_up(ind);
        }
    }
};

ll n, m;
SegTree tree;

ll query() {
	ll q = -inf;
	tree.query(0, n-1, 1, q);
	return q;
}

void solve() {
	cin >> n >> m;
	VLL A(n);
	ll big = -inf, small = inf;
	REP(i,0,n) {
		cin >> A[i];
		big = max(big, A[i]);
		small = min(small, A[i]);
	}
	vector<vector<PLL>> starts(n), ends(n);

	REP(i,0,m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		starts[a].push_back({b,i});
		ends[b].push_back({a,i});
	}

	ll ans = big-small;
	set<ll> ansset;
	set<ll> curset;

	// build my seg tree, and go through each by each.
	tree.build(0, n-1, 1, A);
	REP(i,0,n) {
		// update the tree
		for (PLL newseg : starts[i]) {
			tree.update(i, newseg.first, 1, -1);
			curset.insert(newseg.second);
		}
		
		ll q = query();
		ll diff = q - (A[i] - curset.size());

		if (diff > ans) {
			ans = diff;
			ansset = curset;
		}

		for (PLL oldseg : ends[i]) {
			tree.update(oldseg.first, i, 1, 1);
			curset.erase(oldseg.second);
		}
	}

	cout << ans << endl;
	cout << ansset.size() << endl;
	for (ll a : ansset) {
		cout << a+1 << ' ';
	}
	cout << endl;
	
	


}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}