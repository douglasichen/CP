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

vector<pair<vector<string>, vector<string>>> data;
int c;
hash<string> h;
unordered_map<string,int> ingredients;
unordered_map<string,bool> foundIng;
int k = 0;

vi getLoss(vector<string> like, vector<string> dislike) {
	// int loss=0;
	unordered_map<int,bool> isCustLost;
	vi custLost;
	FOR (i, data.size()) {
		pair<vector<string>, vector<string>> p = data[i];
		vector<string> theyLike = p.F, theyDislike = p.S;
		bool found=false;
		for (string d : theyDislike) {
			for (string iLike : like) {
				if (d==iLike) {
					// loss++;
					if (!isCustLost[i]) {
						custLost.PB(i);
						isCustLost[i] = true;
					}
					found=true;
					break;
				}
			}
			if (found) break;
		}
		if (found) continue;
		for (string iDislike : dislike) {
			for (string l : theyLike) {
				if (iDislike==l) {
					// loss++;
					if (!isCustLost[i]) {
						custLost.PB(i);
						isCustLost[i] = true;
					}
					found = true;
					break;
				}
			}
		}
	}
	// return loss;
	return custLost;
}

void printVPi(vector<pi> v) {
	for (pi p : v) {
		cout << p.F << ' ' << p.S << endl;
	}
}

bool sortBySize(pair<vi,int> a, pair<vi,int> b) {
	return a.F.size() < b.F.size();
}

vector<string> getMaximizingIngr(vector<pair<vi,int>> customersLoss) {
	vector<string> ans;
	vector<bool> invalidCustomers(c);
	unordered_map<string,bool> ingrUsed;
	for (pair<vi,int> p : customersLoss) {
		int customer = p.S;
		if (!invalidCustomers[customer]) {
			for (string j : data[customer].F) {
				if (!ingrUsed[j]) {
					ans.PB(j);
					ingrUsed[j] = true;
				}
			}
			for (int i : p.F) {
				invalidCustomers[i] = true;
			}
		}
		invalidCustomers[customer] = true;
	}
	return ans;
}

int main() {
	cin >> c;
	data = *(new vector<pair<vector<string>, vector<string>>>(c));
	FOR(i,c) {
		int lN; cin>>lN;
		vector<string> l(lN);
		FOR(o,lN) {
			cin>>l[o];

			if (!foundIng[l[o]]) {
				ingredients[l[o]] = k;
				k++;
			}
			foundIng[l[o]]=true;
		}
		
		int dN; cin>>dN;
		vector<string> d(dN);
		FOR(o,dN) {
			cin>>d[o];

			if (!foundIng[d[o]]) {
				ingredients[d[o]] = k;
				k++;
			}
			foundIng[l[o]]=true;
		}
		
		data[i].F = l;
		data[i].S = d;
	}

	// FOR (i,c) {
	// 	cout << i << ": ";

	// 	pair<vector<string>, vector<string>> p = data[i];
	// 	vector<string> l = p.F, d = p.S;
	// 	for (string s : l) cout << ingredients[s] << ' ';
	// 	cout << "| ";
	// 	for (string s : d) cout << ingredients[s] << ' ';
	// 	cout << endl;
	// }

	// vector<pi> customersLoss(c);
	vector<pair<vi,int>> customersLoss(c);
	FOR(i,c) {
		pair<vector<string>, vector<string>> p = data[i];
		vector<string> like = p.F, dislike = p.S;
		// int loss = getLoss(like, dislike);
		// customersLoss[i] = {loss,i};
		vi loss = getLoss(like, dislike);
		customersLoss[i] = {loss,i};
	}
	sort(customersLoss.begin(), customersLoss.end(), sortBySize);
	// for (pair<vi,int> p : customersLoss) {
	// 	for (int i : p.F) cout << i << " ";
	// 	cout << "| " << p.S << endl;
	// }
	vector<string> ans = getMaximizingIngr(customersLoss);
	cout << ans.size() << ' ';
	for (string s : ans) cout << s << ' ';
	cout<<endl;
}