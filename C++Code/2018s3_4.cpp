#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> g;
vector<vector<int>> cams, emps, ans;

vector<int> start;

vector<vector<int>> dirs = {
    {0,1},
    {1,0},
    {-1,0},
    {0,-1},
};

unordered_map<char,vector<int>> arrowDir;


void printG() {
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cout << g[y][x];
        }
        cout << endl;
    }
}

char val(vector<int> pos) {
    return g[pos[0]][pos[1]];
}

void setVal(vector<int> pos, char c) {
    g[pos[0]][pos[1]]=c;
}

vector<int> add(vector<int> a, vector<int> b) {
    return {a[0]+b[0], a[1]+b[1]};
}

vector<int> arrows(vector<int> pos) {
    vector<int> dir=arrowDir[val(pos)];
    vector<int> nextPos=add(pos,dir);
    setVal(pos,'W');

    if (val(nextPos)=='W' || val(nextPos)=='.' || val(nextPos)=='P') {
        return nextPos;
    }
    else {
        return arrows(nextPos);
    }
}

void solve() {
    deque<vector<int>> dq;  // pos, dist
    setVal(start,'W');
    dq.push_back({start[0],start[1],0});

    while (!dq.empty()) {
        vector<int> back = dq.back();
        dq.pop_back();

        vector<int> pos = {back[0],back[1]};
        int dis=back[2];
        ans[back[0]][back[1]]=dis;


        for (vector<int> dir : dirs) {
            vector<int> nextPos=add(pos,dir);

            if (val(nextPos)=='.') {
                dq.push_front({nextPos[0],nextPos[1],dis+1});
                setVal(nextPos,'W');

            }
            else if (val(nextPos)!='W' && val(nextPos)!='P') {
                nextPos=arrows(nextPos);

                if (val(nextPos)=='.') {
                    setVal(nextPos,'W');
                    dq.push_front({nextPos[0],nextPos[1],dis+1});

                }
            }
        }
    }

}

void spread(vector<int> cam) {
    for (vector<int> dir : dirs) {
        vector<int> nextPos=add(cam,dir);
        while (val(nextPos)!='W') {
            if (val(nextPos)=='.') {
                setVal(nextPos,'P');
            }
            nextPos = add(nextPos,dir);
        }
    }
    setVal(cam,'P');
}

int main() {
    arrowDir['R']={0,1};
    arrowDir['L']={0,-1};
    arrowDir['D']={1,0};
    arrowDir['U']={-1,0};


    cin>>n>>m;
    g = *(new vector<vector<char>>(n, *(new vector<char>(m))));
    ans=*(new vector<vector<int>>(n, *(new vector<int>(m,-1))));
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cin>>g[y][x];
            switch(g[y][x]) {
                case '.':
                emps.push_back({y,x});
                break;
                case 'C':
                cams.push_back({y,x});
                break;
                case 'S':
                start={y,x};
            }
        }
    }

    for (vector<int> cam : cams) {
        spread(cam);
    }

    // printG();

    solve();

    for (int i=0; i<emps.size(); i++) {
        vector<int> emp = emps[i];
        cout << ans[emp[0]][emp[1]] << endl;
    }
    
}