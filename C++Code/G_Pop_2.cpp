#include <bits/stdc++.h>
using namespace std;

int N,Q,K=1;
vector<int> V;
vector<int> SZ;

map<int,bool> use;

int start=0;

void rid(int e) {
	map<int,bool>::iterator it=use.find(e);
	if (it!=use.end()) use.erase(it);
}

void printM() {
	map<int,bool> cpy=use;
	for (map<int,bool>::iterator i=use.begin(); i!=use.end(); i++) {
		cout << i->first << ' ';
	}
	cout << endl;
}

void run(int L, int sz) {
	if (start>=L+sz) return;

	bool jump=1;
	if (start>0) {
		if (start<=L && L>0) {
			V[L]=V[start-1];
			K=max(K,V[L]);
			rid(V[L]);

			start=L+1;
			jump=0;
		}
	}
	else {
		start=L;
	}

	if (!jump) {
		int alrHave=V[L];
		int e=1;
		for (int i=start; i<L+sz; i++) {
			if (e==alrHave) e++;
			V[i]=e;
			K=max(K,V[i]);
			e++;

			rid(V[i]);
			start=i;
		}
	}
	else {
		int a=start,b=L+sz;
		int pos=start;
		for (map<int,bool>::iterator i=use.begin(); i!=use.end() && pos<L+sz; i++) {
			V[pos]=i->first;
			K=max(K,V[pos]);
			start=pos;
			pos++;
		}
		
		// rid from a to b
		for (int i=a; i<b; i++) {
			rid(V[i]);
		}
	}
	if (start==N) return;
	if (V[start]!=0) start++;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int mx=1;
	cin>>N>>Q;
	V=vector<int>(N);
	SZ=vector<int>(N);
	for (int i=0; i<Q; i++) {
		int l,r; cin>>l>>r; l--; r--;
		int sz=r-l+1;
		SZ[l]=max(SZ[l],sz);
		mx=max(r-l+1,mx);
	}

	// init use for using all
	for (int i=1; i<=mx; i++) use[i]=1;

	for (int i=0; i<N; i++) {
		int sz=SZ[i];
		if (sz>0) {
			run(i,sz);
		}
		if (V[i]!=0) {
			int e=V[i];
			use[e]=1;
		}
	}

	// later, fill it better with least amount band change
	if (Q) {
		for (int i=0; i<N; i++) {
			if (V[i]==0 && i>0) V[i]=V[i-1];
		}
		for (int i=N-1; i>=0; i--) {
			if (V[i]==0 && i<N-1) V[i]=V[i+1];
		}
	}
	else {
		V=vector<int>(N,1);
	}

	cout << K << endl;
	for (int i=0; i<N; i++) cout << V[i] << (i<N-1 ? " " : "");
	cout << endl;
}