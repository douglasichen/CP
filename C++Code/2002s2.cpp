#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

vector<int> getDivs(int n) {
	vector<int> divs;
	for (int i=1; i<=n; i++) {
		if (prime(i)) {
			if (n%i==0) divs.push_back(i);
		}
	}
	if(divs[divs.size()-1]!=n) divs.push_back(n);
	return divs;
}

void printV(vector<int> v) {
	for (int i : v) cout << i << ' ';
	cout << endl;
}

pair<int,int> red(int a, int b) {
	vector<int> aDiv = getDivs(a), bDiv = getDivs(b);
	vector<bool> aDivMap(a+1), bDivMap(b+1);
	// printV(aDiv);
	// printV(bDiv);
	for (int i : bDiv) bDivMap[i]=true;
	for (int i : aDiv) {
		if (bDivMap[i]) {
			a/=i;
			b/=i;
		}
	}
	return {a,b};
}

string solve(int a, int b) {
	if (a==b) return "1";
	if (a==0) return "0";
	string ans="";
	int whole=a/b;
	if (whole!=0) {
		a -= b * whole;
	}
	ans = to_string(whole);
	if (a==0) return ans;

	if (whole==0) ans="";
	else ans += " ";

	pair<int,int> r = red(a,b);

	ans += to_string(r.first) + "/" + to_string(r.second);
	return ans;
}

int main() {
	int a,b; cin>>a>>b;
	string ans = solve(a,b);
	cout << ans << endl;
}