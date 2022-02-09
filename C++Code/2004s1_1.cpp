#include <bits/stdc++.h>
using namespace std;

bool sorter(string a, string b) {
	return a.size()<b.size();
}

bool isPref(string a, string b) {
	string start="";
	for (int i=0; i<a.size(); i++) {
		start+=b[i];
	}
	
	return start==a;
}

bool isSuff(string a, string b) {
	string end="";
	for (int i=b.size()-a.size(); i<b.size(); i++) {
		end+=b[i];
	}
	return a==end;
}

bool solve(vector<string> g) {
	sort(g.begin(), g.end(), sorter);

	for (int i=0; i<2; i++) {
		for (int o=i+1; o<3; o++) {
			string a=g[i], b=g[o];
			if (isPref(a,b) || isSuff(a,b)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n; cin>>n;
	vector<bool> ans(n);
	for (int i=0; i<n; i++) {
		vector<string> g(3);
		for (int o=0; o<3; o++)
			cin >> g[o];
		ans[i]=solve(g);
	}
	for (bool i : ans)
		cout << (i ? "Yes" : "No") << endl;
}