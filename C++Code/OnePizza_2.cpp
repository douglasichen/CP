#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(x,n) for(int x = 0; x < n; ++x)

#define printV(v) FOR(x,v.size()) cout<<v[x]<<' '; cout<<endl;

int clients;
unordered_map<size_t, pi> data;
unordered_map<size_t, bool> foundIngredient;
vector<string> ingredients;

unordered_map<size_t, int> dislike;
unordered_map<size_t, int> like;

hash<string> h;

void printPi(pi p) {
	cout << p.F << ' ' << p.S << endl;
}

int main() {
	cin>>clients;
	FOR(i,clients) {
		int lN; cin>>lN;
		FOR(o, lN) {
			string s; cin>>s;
			size_t hashed = h(s);
			like[hashed]++;
			if (!foundIngredient[hashed]) {
				ingredients.PB(s);
				foundIngredient[hashed] = true;
			}
		}
		
		int dN; cin>>dN;
		FOR(o, dN) {
			string s; cin>>s;
			size_t hashed = h(s);
			dislike[hashed]++;
			if (!foundIngredient[hashed]) {
				ingredients.PB(s);
				foundIngredient[hashed] = true;
			}
		}
	}
	
	// all ingredients that must be used
	unordered_map<size_t, bool> inAns;
	vector<string> ans;
	FOR(i,ingredients.size()) {
		string s = ingredients[i];
		size_t hashed = h(s);
		if (!dislike[hashed]) {
			ans.PB(s);
			inAns[hashed]=true;
		}
	}
	

	cout << ans.size() << ' ';
	for (string s : ans) {
		cout << s << ' ';
	}
	cout << endl;
}