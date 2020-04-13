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
        ll l,r,v;
    };

    node no[maxn*4];

    void push_up(ll ind){
		no[ind].v = no[lson].v | no[rson].v;
    }
    void push_down(ll ind){
		
    }
    void build(ll l, ll r, ll ind, string & s){
        no[ind].l = l;
        no[ind].r = r;
        if(l == r){
			no[ind].v = (1 << (s[l] - 'a'));
        }else{
            ll mid = (l+r)/2;
            build(l,mid,lson, s);
            build(mid+1,r,rson, s);
            push_up(ind);
        }
    }
    void update(ll l, ll r, ll ind, ll val){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
			no[ind].v = (1 << val);
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
            ans |= no[ind].v;
        }else{
            push_down(ind);
            query(l,r,lson,ans);
            query(l,r,rson,ans);
            push_up(ind);
        }
    }
};

SegTree tree;

void solve() {
	string s;
	cin >> s;
	ll q;
	cin >> q;
	tree.build(0,s.length()-1,1,s);

	REP(i,0,q) {
		ll a;
		cin >> a;
		if (a == 1) {
			ll b;
			char c;
			cin >> b >> c;
			tree.update(b-1,b-1,1,c-'a');
			
		} else {
			ll b, c;
			cin >> b >> c;
			
			ll ans = 0;
			tree.query(b-1,c-1,1,ans);
			ll cnt = 0;
			REP(i,0,32) {
				if ((1<<i) & ans) cnt++;
			}
			cout << cnt << endl;
		}
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}