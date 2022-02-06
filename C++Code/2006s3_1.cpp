#include <bits/stdc++.h>
using namespace std;



bool inter(pair<vector<int>, vector<int>> a, pair<vector<int>, vector<int>>) {
	
	
	return false;
}

int main() {
	int n;
	pair<vector<int>, vector<int>> sight = {{0,0},{0,0}};
	cin >> sight.first[0] >> sight.first[1] >> sight.second[0] >> sight.second[1] >> n;

	vector<vector<pair<vector<int>, vector<int>>>> builds(n);
	
	for (int i=0; i<n; i++) {
		int c; cin>>c;
		vector<vector<int>> points(c, *(new vector<int>(2)));
		for (int j=0; j<c; j++) cin>>points[j][0]>>points[j][1];
		for (int j=0; j<c; j++) {
			pair<vector<int>, vector<int>> edge;
			edge.first = points[j];
			if (j==c-1) edge.second=points[0];
			else edge.second=points[j+1];
			
			builds[i].push_back(edge);
		}
	}

	int ans=0;
	for (vector<pair<vector<int>, vector<int>>> b : builds) {
		for (pair<vector<int>, vector<int>> edge : b) {
			if (inter(edge, sight)) {
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;

}