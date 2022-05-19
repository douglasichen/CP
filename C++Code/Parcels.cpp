#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

vector<int> add(vector<int> a, vector<int> b) {
    return {a[0]+b[0],a[1]+b[1]};
}

void spread(vector<int> p, vector<vector<int>> &mins) {
    
}

int solve(int R, int C, vector<vector<bool>> V) {
    vector<vector<int>> mins(R,*(new vector<int>(C,INT_MAX)));
    for (int y=0; y<R; y++) {
        for (int x=0; x<C; x++) {
            if (V[y][x]) {
                spread({y,x},mins);
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    int ans[T];
    for (int i=0; i<T; i++) {
        int R,C; cin>>R>>C;
        vector<vector<bool>> V(R,*(new vector<bool>(C)));
        for (int y=0; y<R; y++) {
            for (int x=0; x<C; x++) {
                int inp; cin>>inp;
                V[y][x]=inp;
            }
        }
        ans[i]=solve(R,C,V);
    }
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
}