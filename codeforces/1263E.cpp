#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;
const ll maxn = 1e6+5;


#define lson (ind<<1)
#define rson (ind<<1|1)

struct SegTree{
    struct node{
        ll l,r,big,small,lazy;
    };

    node no[maxn*4];

    void push_up(ll ind){
		no[ind].big = max(no[lson].big, no[rson].big);
		no[ind].small = min(no[lson].small, no[rson].small);
    }
    void push_down(ll ind){
		if (no[ind].lazy != 0) {
			no[lson].big += no[ind].lazy;
			no[rson].big += no[ind].lazy;
			no[lson].small += no[ind].lazy;
			no[rson].small += no[ind].lazy;

			no[lson].lazy += no[ind].lazy;
			no[rson].lazy += no[ind].lazy;

			no[ind].lazy = 0;
		}
    }
    void build(ll l, ll r, ll ind){
        no[ind].l = l;
        no[ind].r = r;
        if(l == r){
			no[ind].big = 0;
			no[ind].small = 0;
        }else{
            ll mid = (l+r)/2;
            build(l,mid,lson);
            build(mid+1,r,rson);
            push_up(ind);
        }
    }
    void update(ll l, ll r, ll ind, ll val){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
			no[ind].big += val;
			no[ind].small += val;
			no[ind].lazy += val;
        }else{
            push_down(ind);
            update(l,r,lson,val);
            update(l,r,rson,val);
            push_up(ind);
        }
    }
    void query(ll l, ll r, ll ind, ll & big, ll & small){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
            big = max(big, no[ind].big);
			small = min(small, no[ind].small);
        }else{
            push_down(ind);
            query(l,r,lson,big, small);
            query(l,r,rson,big, small);
            push_up(ind);
        }
    }
};

SegTree tree;
ll arr[maxn] = {0};

void solve() {
	ll n;
	char q[maxn];
	scanf("%lld%s", &n, q);

	tree.build(0,maxn-1,1);
	ll cur = 0;
	REP(i,0,n) {
		if (q[i] == 'L') {
			cur--;
			cur = max(cur, 0LL);
		} else if (q[i] == 'R') {
			cur++;
		} else {
			ll diff = 0;
			diff -= arr[cur];
			
			ll newv = q[i] == '(' ? 1 : q[i] == ')' ? -1 : 0;
			diff += newv;
			arr[cur] = newv;

			tree.update(cur, maxn-1, 1, diff);
		}

		ll big = -inf, small = inf;;
		if (tree.query(maxn-1, maxn-1, 1, big, small), big != 0) {
			printf("-1 ");
		} else {
			big = -inf;
			small = inf;
			tree.query(0, maxn-1, 1, big, small);
			if (small < 0) {
				printf("-1 ");
			} else {
				printf("%lld ", big);
			}
		}
	}
	printf("\n");

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}