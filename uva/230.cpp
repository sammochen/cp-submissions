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

namespace SOLVE {	
	ll find(string & s, ll start, char c) {
		REP(i,start,s.length()) {
			if (s[i] == c) return i;
		}
		return -1;
	}

	pair<string, string> readbook() {
		string s;
		getline(cin, s);

		if (s == "END") {
			return {"", ""};
		}
		
		ll ind1 = 0, ind2 = find(s, 1, '"');
		string title = s.substr(ind1, ind2 - ind1 + 1);
		string author = s.substr(ind2 + 5);
		return {title, author};
	}

	pair<string, string> readquery() {
		string s;
		getline(cin, s);

		if (s == "END") {
			return {"", ""};
		}

		string query = s.substr(0, 6);
		if (query == "SHELVE") return {query, ""};

		string title = s.substr(7);
		return {query, title};
	}

	struct Book {
		string title, author;
	};

	bool operator < (const Book &a, const Book &b) {
  		if (a.author != b.author) return a.author < b.author;
 		return a.title < b.title;
	}

	void main() {
		set<Book> library;
		set<Book> queue;
		map<string, Book> getbook;

		while (1) {
			pair<string, string> b = readbook();
			if (b.first == "") break;
			Book book = {b.first, b.second};
			library.insert(book);
			getbook[book.title] = book;
		}

		while (1) {
			pair<string, string> query = readquery();
			if (query.first == "") break;

			if (query.first == "BORROW") {
				library.erase(getbook[query.second]);
			} else if (query.first == "RETURN") {
				queue.insert(getbook[query.second]);
			} else if (query.first == "SHELVE") {
				for (Book book : queue) {
					library.insert(book);
					set<Book>::iterator itr = library.find(book);
					cout << "Put " << itr->title;
					if (itr == library.begin()) cout << " first" << endl;
					else {
						cout << " after " << (--itr)->title << endl;
					}
				}
				queue.clear();
				cout << "END" << endl;
			}
		}
		
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
