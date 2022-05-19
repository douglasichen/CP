#include <bits/stdc++.h>
using namespace std;


int N,M;
vector<int> V,dsu;
vector<vector<int>> G;

int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

void unite(int a, int b) {
	a=root(a); b=root(b);
	if (a==b) return;
	dsu[a]+=dsu[b];
	dsu[b]=a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    V=vector<int>(N);
	dsu=vector<int>(N,-1);
    G=vector<vector<int>>(N);
    for (int i=0; i<N; i++) cin>>V[i];
    sort(V.begin(),V.end());
    multiset<pair<int,int>> MS;
    MS.emplace(V[0],0);
    G[0].push_back(0);
    for (int i=1; i<N; i++) {
        // cout << "tested: " << V[i] << endl;
        auto lb=MS.lower_bound(make_pair(M-V[i],-1));
        if (lb!=MS.end()) {
            int go=root((*lb).second);
            G[go].push_back(i);
            G[i].push_back(go);
			unite(i,go);
            // cout << "go: " << V[go] << endl;
            auto lb2=lb; lb2++;
            while (lb2!=MS.end() && root((*lb2).second)==root(go)) lb2++; //too slow
            if (lb2!=MS.end()) {
                int go2=(*lb2).second;
                // cout << "go2: " << go2 << endl;
                G[go2].push_back(i);
                G[i].push_back(go2);
				unite(i,go2);
                if (G[go2].size()==2) MS.erase(lb2);
            }
            if (G[go].size()==2) MS.erase(MS.lower_bound(make_pair(V[go],go)));
        }
        
        if (G[i].size()<2) MS.emplace(V[i],i);
        // for (pair<int,int> i : MS) cout << i.first << ' ';
        // cout << endl;
    }

    int start=0;
    vector<int> ans;
    vector<bool> vis(N); vis[start]=1;
    stack<int> S; S.push(start);
    while (!S.empty()) {
        int top=S.top(); S.pop();
        ans.push_back(V[top]);
        for (int i : G[top]) {
            if (i!=top && !vis[i]) {
                vis[i]=1;
                S.push(i);
            }
        }
    }
    if (ans.size()!=N) cout << -1 << endl;
    else {

		for (int i : ans) cout << i << ' ';
		cout << endl;
    }

}