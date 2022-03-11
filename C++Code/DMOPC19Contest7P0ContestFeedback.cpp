#include <bits/stdc++.h>
using namespace std;

float av(vector<float> v) {
	float sum=0;
	for (float f : v) sum+=f;
	return sum/(float)v.size();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	float a,b,c,d; cin>>a>>b>>c>>d;
	vector<float> ans={
		av({a,b}),av({a,c}),av({a,d}),av({b,c}),av({b,d}),av({c,d}),av({a,b,c}),av({a,b,d}),
		av({a,c,d}),av({b,c,d}),av({a,b,c,d})
	};
	for (float s : ans) {
		string d=to_string(s);
		cout << d << endl;
	}
}