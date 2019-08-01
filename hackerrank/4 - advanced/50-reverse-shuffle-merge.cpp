/* 
Original problem: https://www.hackerrank.com/challenges/reverse-shuffle-merge
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll INF = 1e18 + 5;

namespace SOLVE {
	VI freq(26);
	VI keep(26); // freq of reverse
	VI drop(26); // freq of shuffle
	VI fakedrop(26);

	// helper function: returns the lowest available char
	char bestchar() {
		for (int i = 0; i < 26; i++) {
			if (keep[i] > 0) {
				return 'a' + i;
			}
		}
		return -1;
	}

	int sum(VI A) {
		int t = 0;
		for (int a : A) {
			t += a;
		}
		return t;
	}

	void main() {
		// strategy:
		// iterate through in reverse order.
		// if the best char is found, append it to ans
		// if it is not the best char, we can 'drop' it 
		// if the best char cannot be found and we cannot 'drop' anymore, we find the best char possible

		string s, ans = "";
		cin >> s;
		int n = s.length();

		for (char c : s) {
			freq[c - 'a']++;
		}

		// assumes there is always a solution
		for (int i = 0; i < 26; i++) {
			freq[i] /= 2;
		}

		// when keep[i] = 0 or drop[i] = 0, we cannot pick up anymore / drop anymore
		keep = freq, drop = freq;

		// ptr1 holds the pos of the next available char
		int ptr1 = n - 1;

		while (ptr1 >= 0) {
			if (sum(keep) == 0) {
				break;
			}

			fakedrop = drop; // use fakedrop to 'simulate' what would happen
			char best = bestchar();
			char bestsofar = 'z' + 1;

			int ptr2 = ptr1;
			int take = -1; // holds the index of the best option

			// i will keep looking down until i can no longer 'ignore' a char
			while (1) {
				// if the best char is found, take it!
				if (s[ptr2] == best) {
					take = ptr2;
					break;
				}

				// while looking, keep track of the smallest char and the first sight of it
				if (s[ptr2] < bestsofar && keep[s[ptr2] - 'a'] > 0) {
					bestsofar = s[ptr2];
					take = ptr2;
				}

				// if i cannot 'drop' this char, break
				if (fakedrop[s[ptr2] - 'a'] == 0) {
					break;
				}
				fakedrop[s[ptr2] - 'a']--;

				ptr2--;
				if (ptr2 == -1) {
					break;
				}
			}

			// append the best option
			ans += s[take];

			// record it respectively on keep and drop
			keep[s[take] - 'a']--;
			for (int i = take + 1; i <= ptr1; i++) {
				drop[s[i] - 'a']--;
			}

			ptr1 = take - 1;
		}

		cout << ans << endl;

	}
}


signed main() {
	int t;
	//    in(t);
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
