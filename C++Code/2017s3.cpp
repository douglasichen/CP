#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

vi lengthIndexes;
vi lengths(2001);
vi sumAmounts(4001);

void solve() {

}

int main() {
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		int length; cin>>length;
		// lengthIndexes.PB(length);
		lengths[length]++;
	}
	// sort(lengthIndexes.begin(), lengthIndexes.end());
	
	// for (int i=0; i<lengthIndexes.size()-1; i++) {
	// 	for (int j=i+1; j<lengthIndexes.size(); j++) {
	// 		int sum = lengthIndexes[i] + lengthIndexes[j];
	// 		sumAmounts[sum]++;
	// 		// cout<<sum<<endl;
	// 	}
	// }

	for (int i=0; i<lengths.size()-1; i++) {
		// cout<<lengths[i]<<' ';
		if (lengths[i]==0) continue;
		for (int j=i; j<lengths.size(); j++) {
			if (lengths[j]==0) continue;
			
			if (i==j) {
				// int add = 0;
				// for (int o=1; o<lengths[i]; o++) {
				// 	add += o;
				// }
				// sumAmounts[i+j] += add;
				// cout<<lengths[i]<<" of "<<i<<" adds: "<<add<<endl;
				sumAmounts[i+j] += lengths[i] / 2;
			}
			else {
				// cout<<i<<" + "<<j<<endl;
				sumAmounts[i+j] += min(lengths[i],lengths[j]);
			}
		}
	}
	// cout<<endl;

	int biggest = 0;
	for (int i=0; i<sumAmounts.size(); i++) {
		if (sumAmounts[i] > biggest) biggest = sumAmounts[i];
	}
	int difHeights = 0;
	for (int i=0; i<sumAmounts.size(); i++) {
		if (sumAmounts[i] == biggest) difHeights++;
	}
	cout<<biggest<<' '<<difHeights<<endl;
}