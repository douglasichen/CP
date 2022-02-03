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

vector<pair<vector<size_t>, vector<size_t>>> data;
int c;
hash<string> h;
unordered_map<size_t,string> hashToStr;
unordered_map<size_t, vi> customersThatLikeIngr;
unordered_map<size_t, vi> customersThatDislikeIngr;



vi getLoss(int currentCustomer, vector<size_t> like, vector<size_t> dislike) {
	// int loss=0;
	// cout << "getting loss of: " << currentCustomer << endl;
	unordered_map<int,bool> isCustLost;
	vi custLost;
	for (size_t iDislike : dislike) {
		vi loseCustomers = customersThatLikeIngr[iDislike];
		for (int i : loseCustomers) {
			if (!isCustLost[i]) {
				isCustLost[i] = true;
				custLost.PB(i);
			}
		}
	}
	for (size_t iLike : like) {
		vi loseCustomers = customersThatDislikeIngr[iLike];
		for (int i : loseCustomers) {
			if (!isCustLost[i]) {
				isCustLost[i] = true;
				custLost.PB(i);
			}
		}
	}
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

vector<size_t> getMaximizingIngr(vector<pair<vi,int>> customersLoss) {
	vector<size_t> ans;
	vector<bool> invalidCustomers(c);
	unordered_map<size_t,bool> ingrUsed;
	for (pair<vi,int> p : customersLoss) {
		int customer = p.S;
		if (!invalidCustomers[customer]) {
			for (size_t j : data[customer].F) {
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
	string fileName = "e_elaborate.in.txt";
	ifstream in(fileName);
	auto cinbuf = cin.rdbuf(in.rdbuf()); //save and redirect
	
	cin >> c;

	data = *(new vector<pair<vector<size_t>, vector<size_t>>>(c));

	// Taking input:
	FOR(i,c) {
		int lN; cin>>lN;
		vector<size_t> l(lN);
		FOR(o,lN) {
			string s; cin>>s;
			size_t hashed = h(s);
			l[o] = hashed;
			hashToStr[hashed] = s;

			customersThatLikeIngr[hashed].PB(i);
		}
		
		int dN; cin>>dN;
		vector<size_t> d(dN);
		FOR(o,dN) {
			string s; cin>>s;
			size_t hashed = h(s);
			d[o] = hashed;
			hashToStr[hashed] = s;

			customersThatDislikeIngr[hashed].PB(i);
		}
		
		data[i].F = l;
		data[i].S = d;
	}
	
	// Generate the loss
	vector<pair<vi,int>> customersLoss(c);
	float percentI = 0;
	FOR(i,c) {
		pair<vector<size_t>, vector<size_t>> p = data[i];
		vector<size_t> like = p.F, dislike = p.S;
		vi loss = getLoss(i, like, dislike);
		customersLoss[i] = {loss,i};
		// float percent = (float)(i+1)/(float)c * 100.0;
		// percent = floor(percent);
		// if (fmod(percent,1.0)==0 && percent > percentI) {
		// 	cout << "Generation Percent: " << percent << "%" << endl;
		// 	percentI++;
		// }
	}
	// cout << "Loss Generation Complete" << endl;

	// sort the loss by least loss
	sort(customersLoss.begin(), customersLoss.end(), sortBySize);

	// for (pair<vi,int> p : customersLoss) {
	// 	for (int i : p.F) cout << i << " ";
	// 	cout << "| " << p.S << endl;
	// }
	vector<size_t> ans = getMaximizingIngr(customersLoss);
	cout << ans.size() << ' ';
	for (size_t s : ans) cout << hashToStr[s] << ' ';
	cout<<endl;
}