#include <bits/stdc++.h>
using namespace std;

int N,K,Q,KS[5000][2][2],ans[5000];

bool inBounds(int i, vector<int> point) {
    vector<int> a={KS[i][0][0],KS[i][0][1]};
    vector<int> b={KS[i][1][0],KS[i][1][1]};
    return point[0]>=a[0] && point[0]<=b[0] && point[1]>=a[1] && point[1]<=b[1];
}

vector<int> div(vector<int> a, int n) {
    return {a[0]/n, a[1]/n};
}

vector<int> sub(vector<int> a, vector<int> b) {
    return {a[0]-b[0], a[1]-b[1]};
}

vector<int> add(vector<int> a, vector<int> b) {
    return {a[0]+b[0], a[1]+b[1]};
}

vector<int> rot(int i, vector<int> p) {
    vector<int> a={KS[i][0][0],KS[i][0][1]};
    vector<int> b={KS[i][1][0],KS[i][1][1]};

    vector<int> dis2o=div(sub(b,a),2);
    vector<int> o=add(a,dis2o);

    vector<int> offset=sub(p,o);
    vector<int> np={o[0]-offset[1], offset[1]+o[1]};

    return np;
}

int get(int y, int x) {
    vector<int> oldP={y,x};
    vector<int> point=oldP;
    cout << "P: " << point[0] << " " << point[1] << endl;
    for (int i=0; i<K; i++) {
        if (inBounds(i,oldP)) {
            // cout << point[0] << " " << point[1] << " is in bounds i=" << i << endl;
            point=rot(i,point);
        }
    }
    y=point[0]; x=point[1];
    return (y-1)*N+x;
}

int main() {
    cin>>N>>K>>Q;
    for (int i=0; i<K; i++) {
        int a,b,c,d; cin>>a>>b>>c>>d;
        KS[i][0][0]=a;
        KS[i][0][1]=b;
        KS[i][1][0]=c;
        KS[i][1][1]=d;
    }
    for (int i=0; i<Q; i++) {
        int a,b; cin>>a>>b;
        ans[i]=get(a,b);
    }
    for (int i=0; i<Q; i++) {
        cout << ans[i] << endl;
    }
}