#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> &a, vector<int> &b) {
    if (a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int> all('z'+1);
    string s; cin>>s;
    for (char c : s) all[c]++;
    for (int i=0; i<N-1; i++) {
        string d; cin>>d;
        vector<int> has('z'+1);
        for (char c : d) has[c]++;
        for (char c='a'; c<='z'; c++) all[c]=min(all[c],has[c]);
    }
    string S;
    for (char c : s) {
        if (all[c]>0) {
            S+=c;
            all[c]--;
        }
    }

    // priority_queue<vector<int>,vector<vector<int>>,decltype(&sorter)> pq(sorter);
    // int K=S.size();
    // for (int i=0; i<K; i++) {
    //     pq.push({S[i],i});
    // }

    // string ans="";
    // int at=0;
    // while (!pq.empty()) {
    //     vector<int> top=pq.top(); pq.pop();
    //     char val=top[0];
    //     int loc=top[1];
    //     if (loc>=at) {
    //         ans+=val;
    //         at=loc+1;
    //     }
    // }


    if (ans.size()==0) cout << -1 << endl;
    else cout << ans << endl;
}