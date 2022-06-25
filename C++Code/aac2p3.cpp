#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin>>N>>M;
    vector<vector<int>> psa(N+1,vector<int>(M+1));
    char c;
    for (int y=1; y<=N; y++) for (int x=1; x<=M; x++) cin>>c, psa[y][x]=c=='X';
    for (int y=1; y<=N; y++) for (int x=1; x<=M; x++) psa[y][x]+=psa[y-1][x]+psa[y][x-1]-psa[y-1][x-1];
    
    queue<vector<int>> Q;
    vector<vector<bool>> vis, emp(N+1, vector<bool>(M+1));
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int L=0, R=min(N,M);
    while (L<R) {
        vis=emp; while (!Q.empty()) Q.pop();
        int mid=(L+R)>>1;
        mid+=(mid<<1)!=L+R;
        int sz=mid;
        
        if (mid==0) break;
        bool gd=0;
        Q.push({sz,sz}); vis[sz][sz]=1;
        if (psa[sz][sz]) Q.pop();
        while (!Q.empty()) {
            vector<int> a=Q.front(); Q.pop();
            if (a[0]==N && a[1]==M) {
                gd=1;
                break;
            }
            for (vector<int> dir : dirs) {
                vector<int> nxt={dir[0]+a[0], dir[1]+a[1]};
                if (nxt[0]>=sz && nxt[0]<=N && nxt[1]>=sz && nxt[1]<=M) {
                    if (vis[nxt[0]][nxt[1]]) continue;
                    int cnt=psa[nxt[0]][nxt[1]]-psa[nxt[0]-sz][nxt[1]]-psa[nxt[0]][nxt[1]-sz]+psa[nxt[0]-sz][nxt[1]-sz];
                    if (!cnt) Q.push(nxt), vis[nxt[0]][nxt[1]]=1;
                }
            }
        }
        if (gd) L=mid;
        else R=mid-1;
    }
    cout << L << endl;

}