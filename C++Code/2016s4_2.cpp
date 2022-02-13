#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> balls;
int maxBall=0;


void rec(vector<int> current, vector<int> comb) {

	// apply the combination
	if (comb.size()>=2) {
		int sum=0;
		for (int i : comb) sum+=current[i];
		current.erase(current.begin()+comb[0]+1, current.begin()+comb.back()+1);
		// current.emplace(current.begin()+comb[0], sum);
		current[comb[0]]=sum;

		// max ball
		maxBall=max(sum,maxBall);
	}

	// create new options
	vector<vector<int>> options;
	int cSize=current.size();
	for (int i=0; i<cSize-1; i++) {
		int a=current[i], b=current[i+1];
		if (a==b) {
			options.push_back({i,i+1});
		}
		if (i<cSize-2) {
			int c=current[i+2];
			if (a==c) {
				options.push_back({i,i+1,i+2});
			}
		}
	}
	for (vector<int> op : options) {
		// recurse options
		rec(current, op);
	}
}

int main() {
	// data
	cin>>n;
	balls=*(new vector<int>(n));
	for (int i=0; i<n; i++) {
		cin>>balls[i];
		maxBall=max(balls[i],maxBall);
	}

	rec(balls, {});

	cout << maxBall << endl;
	
}