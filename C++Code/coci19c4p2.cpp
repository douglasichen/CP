#include <bits/stdc++.h>
using namespace std;

vector<int> V,A;

bool cmp(int a, int b) {
    return A[a]>A[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
    int N,K; cin>>N>>K;
    V=vector<int>(N);
    vector<int> F(1e6+1),ans(1e6+1),inds;
    for (int i=0; i<N; i++) {
        cin>>V[i];
        if (!F[V[i]]) {
            inds.push_back(A.size());
            A.push_back(V[i]);
        }
        F[V[i]]++;
    }
    sort(inds.begin(),inds.end(),cmp);
	int behind=0;
    for (int i=0; i<inds.size(); i++) {
        int val=A[inds[i]];
        if (val==K) ans[val]+=behind;
		else if (val>K) {
			int P=val-K;
			for (int i=2; i*i<=P; i++) {
				if (P%i==0) {
					int a=i,b=P/i;
					if (val%a==K) ans[val]+=F[a];
					if (a!=b) {
						if (val%b==K) ans[val]+=F[b];
					}
				}
			}
			if (K) {
				if (val%P==K) ans[val]+=F[P];
			}
			if (!K) {
				if (F[val]) ans[val]+=F[val]-1;
				if (F[1]) ans[val]+=F[1]-(val==1);
			}
		}
		behind+=F[val];
    }
    for (int i : V) cout << ans[i] << ' ';
    cout << endl;
    
}