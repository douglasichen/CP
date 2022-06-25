#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	bool gd=1;
	vector<int> dA(N+2), dB(N+2), psa(N+1), startA(N+2), endA(N+1), startB(N+1), endB(N+1), V(N+2), cntA(N+1);
	vector<vector<int>> A,B;
	for (int i=0; i<M; i++) {
		int x,l,r; cin>>x>>l>>r;
		if (x==1) dA[l]++, dA[r+1]--, startA[l]++, endA[r]++;
		else dB[l]++, dB[r+1]--, startB[l]++, endB[r]++;
	}
	for (int i=1; i<=N; i++) dA[i]+=dA[i-1], dB[i]+=dB[i-1];

	vector<int> intv(2);
	for (int i=1; i<=N; i++) {
		if (!startA[i] && !endA[i]) continue;
		if (startA[i]==dA[i]) intv[0]=i;
		if (endA[i]==dA[i]) intv[1]=i, A.push_back(intv);
	}
	for (int i=1; i<=N; i++) {
		if (!startB[i] && !endB[i]) continue;
		if (startB[i]==dB[i]) intv[0]=i;
		if (endB[i]==dB[i]) intv[1]=i, B.push_back(intv);
	}
	//
	

	fill(startA.begin(), startA.end(), 0), fill(endA.begin(), endA.end(), 0);
	for (vector<int> v : A) {
		for (int i=v[0], val=1; i<=v[1]; i++, val++) V[i]=val, cntA[i]=1, psa[i]=1;
		startA[v[0]]=1, endA[v[1]]=1;
	}
	for (int i=1; i<=N; i++) psa[i]+=psa[i-1];

	
	for (vector<int> v : B) {
		int cnt=psa[v[1]]-psa[v[0]-1];
		if (cnt>2) gd=0;
		else if (cnt==2) {
			if (!cntA[v[0]] || !cntA[v[1]] || !endA[v[0]] || !startA[v[1]]) gd=0;
		}

		if (!gd) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (vector<int> v : B) {
		if (V[v[1]] || !V[v[1]+1]) {
			for (int i=v[1], val=1; i>=v[0]; i--, val++) {
				val=max(val,V[i]);
				V[i]=val;
			}
			if (V[v[0]]==V[v[0]-1]) V[v[0]]++;
		}
		else {
			vector<int> lb=*lower_bound(A.begin(), A.end(), vector<int>{v[1]+1,0});
			int costA=v[1]-v[0]+1;
			costA=max(costA,V[v[0]]);
			costA+=costA==V[v[0]-1];
			costA=max(costA, lb[1]-lb[0]+1+1);

			int costB=v[1]-v[0]+1+1;
			costB=max(costB,V[v[0]]);
			costB+=costB==V[v[0]-1];
			costB=max(costB,lb[1]-lb[0]+1);

			int val=2;
			if (costA<costB) {
				val=1;
				for (int i=lb[0]; i<=lb[1]; i++) V[i]++;
			}
			for (int i=v[1]; i>=v[0]; i--, val++) {
				val=max(val,V[i]);
				V[i]=val;
			}
			if (V[v[0]]==V[v[0]-1]) V[v[0]]++;
		}
	}

    int at=0;
    for (int i=1; i<=N; i++) {
        if (V[i]) break;
        at=i;
    }
    for (int i=at; i>=1; i--) {
        V[i]=1;
        while (V[i]==V[i-1] || V[i]==V[i+1]) V[i]++;
    }
    at=N+1;
    for (int i=N; i>=1; i--) {
        if (V[i]) break;
        at=i;
    }
    for (int i=at; i<=N; i++) {
        V[i]=1;
        while (V[i]==V[i-1] || V[i]==V[i+1]) V[i]++;
    }

	for (int i=1; i<=N; i++) {
		if (!V[i]) {
			V[i]=1;
			while (V[i]==V[i-1] || V[i]==V[i+1]) V[i]++;
		}
	}

	for (int i=1; i<=N; i++) cout << V[i] << ' '; cout << endl;
}