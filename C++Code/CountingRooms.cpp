#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<bool>> vis;
int ans=0;

vector<vector<int>> dirs = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

vector<int> add(vector<int> a, vector<int> b) {
    return {a[0]+b[0],a[1]+b[1]};
}

bool inBound(vector<int> v) {
    return v[0]>=0 && v[0]<N && v[1]>=0 && v[1]<M;
}

bool bfs(vector<int> start) {
    if (vis[start[0]][start[1]]) return 0;
    vis[start[0]][start[1]]=1;
    deque<vector<int>> dq; dq.push_back(start);
    while (!dq.empty()) {
        vector<int> back=dq.back(); dq.pop_back();
        for (vector<int> dir : dirs) {
            vector<int> nxt=add(back,dir);
            if (inBound(nxt) && !vis[nxt[0]][nxt[1]]) {
                dq.push_front(nxt);
                vis[nxt[0]][nxt[1]]=1;
            }
        }
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    vis=vector<vector<bool>>(N,vector<bool>(M));
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            char c; cin>>c;
            if (c=='#') {
                vis[y][x]=1;
            }
        }
    }

    int ans=0;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            ans+=(bfs({y,x}));
        }
    }
    cout << ans << endl;
}