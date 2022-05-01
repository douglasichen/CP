#include <bits/stdc++.h>
using namespace std;

int N;
string s;

bool sorter(int a, int b) {
	if (s[a]==s[b]) return a>b;
	return s[a]<s[b];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	cin>>s;
	vector<int> locs(N);
	for (int i=0; i<N; i++) locs[i]=i;
	sort(locs.begin(), locs.end(), sorter);
	
	vector<bool> taken(N);
	int cur=0, end=N-1;
	string a="",b="";
	while (a.size()+b.size()<N) {
		// b
		while (taken[end] && end>0) end--;
		if (taken[end]) break;
		taken[end]=1;
		b+=s[end];

		// check
		if (a.size()+b.size()==N) break;

		// a
		while (taken[locs[cur]] && cur<N-1) cur++;
		taken[locs[cur]]=1;
		a+=s[locs[cur]];
	}
	// cout << a << ' ' << b << endl;
	if (a<b) {
		cout << "DA" << endl;
	}
	else {
		cout << "NE" << endl;
	}
	cout << a << endl;
	
}