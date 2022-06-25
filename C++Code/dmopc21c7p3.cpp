#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int N,M;
vector<vector<int>> G;
vector<int> ts;
vector<bool> bad, vis0, vis1, vis;
queue<int> lQ;

void dfs(int node) {
    vis1[node]=1;
    vis0[node]=1;
    for (int child : G[node]) {
        if (vis0[child]) lQ.push(child), vis[child]=1;
        else if (!vis1[child]) dfs(child);
    }
    vis0[node]=0;
    ts.push_back(node);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    cin>>N>>M;

    vector<bool> have(N+1);
	vector<int> B(N+1), deg(N+1);
    vector<long long> hit(N+1);
    vector<vector<int>> R(N+1,vector<int>{});
    
    bad.assign(N+1,0);
    vis0.assign(N+1,0);
    vis1.assign(N+1,0);
    vis.assign(N+1,0);
    G.assign(N+1,{});

	for (int i=1; i<=N; i++) cin>>B[i];
	for (int i=0,a,b; i<M; i++) cin>>a>>b, G[a].push_back(b), R[b].push_back(a), deg[b]++;
    int cnt=0;
    for (int i=1; i<=N; i++) if (deg[i]==0) dfs(i),cnt++;
    if (cnt==0) {
        bool all0=1;
        for (int i=1; i<=N; i++) if (B[i]) all0=0;
        if (all0) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    
    while (!lQ.empty()) {
        int node=lQ.front(); lQ.pop();
        if (B[node]) {
            cout << -1 << endl;
            return 0;
        }
        for (int child : R[node]) {
            if (!vis[child]) lQ.push(child), vis[child]=1;
        }
    }

    reverse(ts.begin(),ts.end());
	int ans=0;
    for (int i : ts) {
		int b=B[i];
		if (hit[i]&1) b=!b;
		ans+=b;
        hit[i]+=b;
        for (int child : G[i]) hit[child]+=hit[i];
	}
	cout << ans << endl;
}