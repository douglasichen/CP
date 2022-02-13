#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> data;

long long sum(int c) {
	long long ans=0;
	for (vector<int> person : data) {
		int p=person[0], w=person[1], d=person[2];
		int dif=abs(p-c);
		if (dif>d) {
			int trav=dif-d;
			long long time=(long long)trav*(long long)w;
			ans+=time;
		}
	}
	return ans;
}

int main() {
	// data
	int furthest=0;
	cin>>n;
	data=*(new vector<vector<int>>(n, *(new vector<int>(3))));
	for (int i=0; i<n; i++) {
		cin>>data[i][0]>>data[i][1]>>data[i][2];
		furthest=max(furthest,data[i][0]);
	}

	// for (int i=1; i<=furthest; i++) {
	// 	cout << sum(i) << ' ';
	// }
	// cout << endl;
	long long ans=0;
	int left=0, right=furthest;
	while (left<right) {
		int m1=(left+right)/2;
		int m2=m1+1;
		int sum1=sum(m1), sum2=sum(m2);
		if (sum1==sum2) {
			ans=sum1;
			break;
		}
		else {
			if (sum1<sum2) {
				right=m1;
			}
			else {
				left=m2;
			}
		}
		if (left==right) ans=sum(left);
		// for (int i=left; i<=right; i++) {
		// 	cout << sum(i) << ' ';
		// }
		// cout << endl;
	}
	cout << ans << endl;
}