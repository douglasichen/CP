#include <bits/stdc++.h>
using namespace std;

int M,N;
vector<int> V;

bool sorter(int i, int j) {
	if (V[i]==V[j]) return i>j;
	return V[i]>V[j];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>M>>N;
	V=vector<int>(N);
	for (int i=0; i<N; i++) cin>>V[i];

	int ans=0;
	priority_queue<int,vector<int>,decltype(&sorter)> pq(sorter);
	vector<bool> taken(N);	// indexes taken
	taken[0]=1;
	
}