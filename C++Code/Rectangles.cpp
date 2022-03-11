#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<int,bitset<40002>> has;
vector<vector<int>> points;

vector<int> absSub(vector<int> a, vector<int> b) {
	return {abs(a[0]-b[0]), abs(a[1]-b[1])};
}

vector<int> filter(vector<int> v) {
	return {v[0]+20000, v[1]+20000};
}

int rec(vector<int> a, vector<int> b) {
	if (a[0]==b[0] || a[1]==b[1]) return 0;
	
	vector<int> c={a[0],b[1]}, d={b[0],a[1]};
	if (!has[c[0]][c[1]] || !has[d[0]][d[1]])	
		return 0;
	
	c=filter(c);
	d=filter(d);

	vector<int> absDif=absSub(a,b);
	return absDif[0]*absDif[1];
}

int main() {
	cin>>N;

	for (int i=0; i<N; i++) {
		int a,b; cin>>a>>b;
		a+=20000; b+=20000;
		has[a][b]=1;
		points.push_back({a,b});
	}
	int ans=0;
	for (int i=0; i<N-1; i++) {
		for (int o=i+1; o<N; o++) {
			vector<int> a=points[i], b=points[o];
			int area=rec(a,b);
			ans=max(ans,area);
		}
	}
	cout << ans << endl;
}