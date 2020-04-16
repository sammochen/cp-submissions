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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

void in(string & s) {
	char buf[20]; // note the 100 limit
	ll a = scanf("%19s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

VLL P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

VLL dp(305, -1);
ll pf(ll x) {
	ll og = x;
	if (dp[x] != -1) return dp[x];
	ll ans = 0;
	REP(i,0,P.size()) {
		ll f = P[i];
		while (x % f == 0) {
			ans |= (1LL << i);
			x /= f;
		}
		if (x == 1) break;
	}
	dp[og] = ans;
	return ans;
}

VLL dp2(64, -1);
ll invp(ll i) {
	if (dp2[i] != -1) return dp2[i];
	dp2[i] = pow(P[i], mod-2);
	return dp2[i];
}

#define lson (ind<<1)
#define rson (ind<<1|1)

const ll maxn = 400005;
ll A[maxn];

struct SegTree{
    struct node{
        ll l,r,size,v,p,lazyv,lazyp;
    };

    node no[maxn*4];

    void push_up(ll ind){
		no[ind].p = no[lson].p | no[rson].p;
		no[ind].v = no[lson].v * no[rson].v % mod;
    }

    void push_down(ll ind){
		if (no[ind].lazyv != 1) {
			no[lson].v *= pow(no[ind].lazyv, no[lson].size);
			no[lson].v %= mod;
			
			no[lson].lazyv *= no[ind].lazyv;
			no[lson].lazyv %= mod;
		
			no[rson].v *= pow(no[ind].lazyv, no[rson].size);
			no[rson].v %= mod;
			
			no[rson].lazyv *= no[ind].lazyv;
			no[rson].lazyv %= mod;
		
			no[ind].lazyv = 1;
		}
		if (no[ind].lazyp != 0) {

			no[lson].p |= no[ind].lazyp;
			no[lson].lazyp |= no[ind].lazyp;

			no[rson].p |= no[ind].lazyp;
			no[rson].lazyp |= no[ind].lazyp;

			no[ind].lazyp = 0;
		}
    }
    void build(ll l, ll r, ll ind){
        no[ind].l = l;
        no[ind].r = r;
		no[ind].size = r-l+1;
		no[ind].lazyv = 1;
		no[ind].lazyp = 0;
		
        if(l == r){
			no[ind].v = A[l];
			no[ind].p = pf(A[l]);
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
			no[ind].v *= pow(val, no[ind].size);
			no[ind].v %= mod;
			no[ind].p |= pf(val);
			
			no[ind].lazyv *= val;
			no[ind].lazyv %= mod;

			no[ind].lazyp |= pf(val);

        }else{
            push_down(ind);
            update(l,r,lson,val);
            update(l,r,rson,val);
            push_up(ind);
        }
    }
    void query(ll l, ll r, ll ind, ll & ans, ll & primes){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
            ans *= no[ind].v;
			ans %= mod;
			primes |= no[ind].p;
        }else{
            push_down(ind);
            query(l,r,lson,ans,primes);
            query(l,r,rson,ans,primes);
            push_up(ind);
        }
    }
};

SegTree tree;

void solve() {

	ll n, q;
	in(n,q);

	REP(i,0,n) in(A[i]);
	tree.build(0, n-1, 1);

	REP(i,0,q) {
		string s;
		in(s);
		if (s == "TOTIENT") {
			ll l, r;
			in(l,r);
			l--;r--;

			ll ans = 1, primes = 0;
			tree.query(l,r,1,ans,primes);

			REP(j,0,P.size()) {
				if ((1LL << j) & primes) {
					ans *= P[j] - 1;
					ans %= mod;
					ans *= invp(j);
					ans %= mod;
				}
			}
			printf("%lld\n",ans);
		} else {
			ll l, r, v;
			in(l,r,v);
			l--;r--;

			tree.update(l,r,1,v);
		}
	}


}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}