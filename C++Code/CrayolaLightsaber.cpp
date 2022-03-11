#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> cnt;

bool sorter(string a, string b) {
	return cnt[a]>cnt[b];
}

int main() {
	
	int n; cin>>n;
	vector<string> cols;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		if (cnt[s]==0) cols.push_back(s);
		cnt[s]++;
	}

	sort(cols.begin(), cols.end(), sorter);
	
	string cur=cols[0];
	
	int size=1;
	cnt[cur]--;

	while (size<n) {
		bool step=0;
		for (string s : cols) {
			if (s!=cur) {
				if (cnt[s]>0) {
					cur=s;
					cnt[s]--;
					size++;
					step=1;
					break;
				}
			}
		}
		if (!step) break;
	}
	
	cout << size << endl;
}