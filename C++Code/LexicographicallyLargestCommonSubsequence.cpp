#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> &a, vector<int> &b) {
    // if (a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    bitset<'z'+1> ah;
    int N; cin>>N;
    string V[N];
    for (int i=0; i<N; i++) {
        cin>>V[i];
        bitset<'z'+1> h;
        for (int o=0; o<V[i].size(); o++) {
            h[V[i][o]]=1;
        }
        if (i==0) ah=h;
        else ah=(ah&h);
    }
    
    string ans="";
    for (int i=0; i<N; i++) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&sorter)> pq(sorter);
        for (int o=0; o<V[i].size(); o++) {
            if (ah[V[i][o]]) pq.push({o,V[i][o]});
        }
        int start=0;
        string s="";
        while (!pq.empty()) {
            vector<int> top=pq.top(); pq.pop();
            if (start<=top[0]) {
                start=top[0]+1;
                s+=top[1];
            }
        }
        // V[i]=s;
        if (i==0) ans=s;
        else if (ans.size()>s.size()) ans=s;
    }
    if (ans.size()==0) cout << -1 << endl;
    else cout << ans << endl;


}