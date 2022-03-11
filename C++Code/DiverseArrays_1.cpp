#include <bits/stdc++.h>
using namespace std;

int N,K,V[1000000];
vector<int> has(1000000+1);


int main() {
	cin>>N>>K;
	for (int i=0; i<N; i++) {
		cin>>V[i];
	}

	int dis=0;
	for (int i=0; i<N-1; i++) {
		if (i>0) {
			int behind=V[i-1];
			has[behind]--;
			if (has[behind]==0) dis--;
		}
		for (int o=i; o<N; o++) {
			has[V[o]]++;
			if (has[V[o]]>1)
				dis--;
		}
	}
}