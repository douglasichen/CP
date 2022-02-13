#include <bits/stdc++.h>
using namespace std;

int G,P;
vector<vector<int>> goTo;

bool sorter(vector<int> a, vector<int> b) {
	if (a[1]==b[1])
		return a[0]<b[0];
	return a[1] < b[1];
}

int main() {
	cin>>G>>P;
	goTo=*(new vector<vector<int>>(P+1,*(new vector<int>(2))));
	for (int i=1; i<=P; i++) {
		cin>>goTo[i][1];
		goTo[i][0]=i;
	}
	sort(goTo.begin(), goTo.end(), sorter);

	// for (vector<int> go : goTo) {
	// 	cout << go[0] << " " << go[1] << endl;
	// }

	unordered_map<int,bool> failed;
	int aval=1;
	for (int i=1; i<=P; i++) {
		int index=goTo[i][0], gate=goTo[i][1];
		if (gate<aval)
			failed[index]=1;
		else
			aval++;
	}

	int ans=0;
	for (int i=1; i<=P; i++) {
		if (failed[i])
			break;
		ans++;
	}
	cout << ans << endl;
}