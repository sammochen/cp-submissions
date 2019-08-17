/*
Original problem: https://www.hackerearth.com/zh/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/
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

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	struct trienode {
		struct trienode *children[2];
		bool end;
	};

	trienode* newNode(void) {
		trienode *newnode = new trienode;
		newnode->end = false;
		REP(i,0,2) {
			newnode->children[i] = NULL;
		}
		return newnode;
	}

	void insert(trienode *root, string s) {
		trienode *ptr = root;
		for (int i = 0; i < s.length(); i++) {
			int child = s[i] - '0';
			if (!ptr->children[child]) {
				ptr->children[child] = newNode();
			}
			ptr = ptr->children[child];
		}
		ptr->end = true;
	}

	string search(trienode *root, string s) {
		trienode *ptr = root;
		string ans = "";
		for (int i = 0; i < s.length(); i++) {
			if (ptr->children[0] && ptr->children[1]) {
				ans += s[i];
				ptr = ptr->children[s[i] - '0'];
			} else {
				ans += ptr->children[0] ? "0" : "1";
				ptr = ptr->children[0] ? ptr->children[0] : ptr->children[1];
			}
		}
		return ans;
	}

	int BIT = 31;
	
	string bstring(int x) {
		string ans = "";
		for (int bit = BIT; bit >= 0; bit--) {
			ans += (x & (1 << bit)) ? "1" : "0";
		}
		return ans;
	}

	int bint(string s) {
		int bit = BIT;
		int ans = 0;
		for (char c : s) {
			ans += (c - '0') * (1 << bit);
			bit--;
		}
		return ans;
	}

    void main() {
        int q, a, b;
		int x = 0; // xor
		trienode* r = newNode();
		insert(r, bstring(0));

		cin >> q;
		REP(i,0,q) {
			cin >> a;
			if (a == 1) {
				cin >> b;
				insert(r, bstring(b ^ x));
			}
			if (a == 2) {
				cin >> b;
				x ^= b;
			}
			if (a == 3) {
				string find = search(r, bstring(x));
				int ans = bint(find) ^ x;
				cout << ans << endl;
			}
		}
		
    }
}


signed main() {
	int t;
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}