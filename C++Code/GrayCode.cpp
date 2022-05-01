#include <bits/stdc++.h>
using namespace std;


bool sorter(string a, string b) {
	return 
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	int mx=1<<N;
	vector<string> ans;
	for (int i=0; i<mx; i++)	{
		int e=i;
		string s="";
		int cnt=N;
		while (cnt) {
			s+=(e&1 ? "1" : "0");
			e>>=1;
			cnt--;
		}
		ans.push_back(s);
	}

	sort(ans.begin(),ans.end(),sorter);
	for (string s : ans) cout << s << endl;
}
