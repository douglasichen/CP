#include <bits/stdc++.h>
using namespace std;

long long n,d,k,x,p;

bool solve(vector<long long> a) {
	// float pT = (float)d/(float)p;
	// cout << "pt: " << pT << endl;
	// sort(a.begin(), a.end(), greater<int>());
	
	// vector<int> fast;
	// for (int spd : a) {
	// 	float t = (float)d/(float)spd;
	// 	if (t<=pT) fast.push_back(spd);
	// }

	// sort(fast.begin(), fast.end());
	// for (int spd : fast) {
	// 	if (k==0) return false;
	// 	float t = (float)d/(float)spd;
	// 	while (t<=pT) {
	// 		float slowSpd = (float)spd * ((100.0 - (float)x))/100.0;
	// 		float slowT = (float)d/slowSpd;
	// 		t = slowT;
	// 		k--;
	// 		if (k==0) break;
	// 	}
	// }
	
	float mSpd = (float)p;
	vector<float> fast;
	for (long long spd : a) {
		if (spd>=p) fast.push_back((float)spd);
	}

	sort(fast.begin(), fast.end());

	for (float spd : fast) {
		if (k==0) return false;
		while (spd >= mSpd) {
			spd = (spd-(float)x)/100.0;
			k--;
			if (k==0) {
				// cout << "Broke out" << endl;
				break;
			}
		} 
		if (spd >= mSpd) return false;
		// cout << spd << ' ';
	}
	// cout << endl;

	// cout << mSpd << endl;

	return true;
}

int main() {
	cin>>n>>d>>k>>x;
	vector<long long> a(n);
	for (long long i=0; i<n; i++) cin>>a[i];
	cin>>p;

	bool ans = solve(a);
	cout << (ans ? "YES" : "NO") << endl;
}