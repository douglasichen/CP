#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> h;

bool works(int length) {
    int myK=k;
    unordered_map<int,bool> covered;
    int cov=0;
    int kUse=0;
    for (int i=0; i<n; i++) {
        int home=h[i];
        int rBound=home+length*2;
        cov++;
        kUse++;
        for (int o=i+1; o<n; o++) {
            if (h[o] > rBound) {
                // cout << h[o] << " not in bounds of home: " << home << endl;
                break;
            }
            else {
                // cout << h[o] << " is in bounds of home: " << home << endl;
                i++;
                cov++;
            }
        }
        if (kUse>k) break;
    }

    bool ans=kUse<=k;
    return ans;
}

int main() {
    cin>>n;
    h=*(new vector<int>(n));
    for (int i=0; i<n; i++) {
        cin>>h[i];
    }
    cin >> k;

    sort(h.begin(), h.end());

    cout << works(4000) << endl;

    
    // int left = 0, right=500000;
    // while (left+1<right) {
    //     int mid=(left+right)/2;
    //     if (works(mid)) {
    //         right=mid;
    //     }
    //     else {
    //         left=mid;
    //     }
    // }
    // cout << right << endl;
}