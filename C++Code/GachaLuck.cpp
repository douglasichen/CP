#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int n,k; cin>>n>>k;
	string s; cin>>s;
	
	int start=0;
	vector<int> sizes;
	int mSize=0;
	for (int i=0; i<s.size(); i++) {
		bool val=s[i]-'0';
		if (!val) mSize++;
		else {
			sizes.push_back(mSize);
			mSize=0;
		}
	}
	if (mSize) sizes.push_back(mSize);

	// for (int i : sizes) cout << i << ' ';
	// cout << endl;
	
	sort(sizes.begin(), sizes.end(), greater<int>());
	int ans=0;
	for (int i=0; i<min(k,(int)sizes.size()); i++) {
		ans+=sizes[i];
	}

	cout << ans << endl;
}