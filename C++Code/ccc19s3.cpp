#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<vector<ll>> V(3,vector<ll>(3));
vector<vector<bool>> has(3,vector<bool>(3)); 
int unk=9;

void fl() {
	int cnt=1;
	while (cnt) {
		cnt=0;
		for (int y=0; y<3; y++) {
			long long a=V[y][0], b=V[y][1], c=V[y][2];
			bool hA=has[y][0], hB=has[y][1], hC=has[y][2];
			if (hA+hB+hC==2) {
				if (!hA) a=2*b-c, hA=1;
				else if (!hB) b=(a+c)/2, hB=1;
				else c=2*b-a, hC=1;
				
				V[y]=vector<ll>{a,b,c};
				has[y]=vector<bool>{hA,hB,hC};
				cnt++;
				unk--;
			}
		}
		for (int x=0; x<3; x++) {
			long long a=V[0][x], b=V[1][x], c=V[2][x];
			bool hA=has[0][x], hB=has[1][x], hC=has[2][x];
			if (hA+hB+hC==2) {
				if (!hA) a=2*b-c, hA=1;
				else if (!hB) b=(a+c)/2, hB=1;
				else c=2*b-a, hC=1;

				V[0][x]=a, V[1][x]=b, V[2][x]=c;
				has[0][x]=hA, has[1][x]=hB, has[2][x]=hC;
				cnt++;
				unk--;
			}
		}
	}
}

vector<vector<int>> dirs = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

vector<int> add(vector<int> a, vector<int> b) {
	return {a[0]+b[0],a[1]+b[1]};
}

bool in(vector<int> a) {
	return a[0]>=0 && a[0]<3 && a[1]>=0 && a[1]<3;
}

void pt() {
	if (unk==9) has[0][0]=1,unk--;
	else {
		vector<int> d={-1,-1};
		for (int y=0; y<3; y++) {
			for (int x=0; x<3; x++) {
				if (has[y][x]) {
					d={y,x};
					
					// can?
					for (vector<int> dir : dirs) {
						vector<int> nxt=add(d,dir);

						if (in(nxt) && !has[nxt[0]][nxt[1]]) {
							V[nxt[0]][nxt[1]]=V[d[0]][d[1]];
							has[nxt[0]][nxt[1]]=1;
							unk--;
							return;
						}
					}
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);


	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			string inp; cin>>inp;
			if (inp!="X") {
				int val=stoi(inp);
				has[y][x]=1;
				V[y][x]=val;
				unk--;
			}
		}
	}

	while (unk) {
		fl();
		pt();
	}

	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			cout << V[y][x] << ' ';
		}
		cout << endl;
	}
}