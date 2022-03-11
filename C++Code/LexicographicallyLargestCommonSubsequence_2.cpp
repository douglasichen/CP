#include <bits/stdc++.h>
using namespace std;

bool sorter(vector<int> &a, vector<int> &b) {
    if (a[1]==b[1]) return a[0]>b[0];
    return a[1]<b[1];
}

int main() {
   	cin.sync_with_stdio(0);
    cin.tie(0);
    
	unordered_map<char,int> minCnt;
    bitset<'z'+1> ah;
    int N; cin>>N;
    string V[N];
    for (int i=0; i<N; i++) {
        cin>>V[i];

		unordered_map<char,int> myCnt;
        bitset<'z'+1> h;
        for (int o=0; o<V[i].size(); o++) {
            h[V[i][o]]=1;
			myCnt[V[i][o]]++;
        }
        
		// bitset
		if (i==0) ah=h;
        else ah=(ah&h);
		
		// cnt
		if (i==0) minCnt=myCnt;
		else {
			for (char c='a'; c<='z'; c++)
				minCnt[c]=min(minCnt[c], myCnt[c]);
		}
    }
    
    
	// answer...
	string ans="";
	priority_queue<vector<int>, vector<vector<int>>, decltype(&sorter)> pq(sorter);
	for (int o=0; o<V[0].size(); o++) {
		char c=V[0][o];
		if (ah[c] && minCnt[c]>0) {
			pq.push({o,c});
			minCnt[c]--;
		}
	}

	int start=0;
	while (!pq.empty()) {
		vector<int> top=pq.top(); pq.pop();
		if (top[0]>=start) {
			start=top[0]+1;
			ans+=top[1];
		}
	}
    if (ans.size()==0) cout << -1 << endl;
    else cout << ans << endl;


}