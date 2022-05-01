#include <bits/stdc++.h>
using namespace std;


struct E {
	int pos;
	mutable int left,right;
	E(int p, int l, int r) {
		pos=p;
		left=l;
		right=r;
	}
};

struct cmp {
  bool operator()(const E &a, const E &b) {
    return a.pos < b.pos;
  }
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	pair<bool,set<E,cmp>::iterator> best; // is right, it
	int ans=1;
	int X,N; cin>>X>>N;
	set<E,cmp> S;
	for (int i=0; i<N; i++) {
		int inp; cin>>inp;
		const E newE(inp,0,0);
		auto lower=S.lower_bound(newE), upper=S.upper_bound(newE);
		
		// non yet
		if (lower==S.begin() && upper==S.end()) {
			newE.left=newE.pos;
			newE.right=X-newE.pos;
			S.emplace(newE);
			
			if (newE.right>newE.left) {
				ans=newE.right;
				best.first=1;
			}
			else {
				ans=newE.left;
				best.first=0;
			}
			best.second=S.find(newE);
		}
		else if (lower==S.begin()) {
			newE.left=newE.pos;
			newE.right=(*upper).pos-newE.pos;
			
			const E newUpper((*upper).pos,newE.right,(*upper).right);
			S.emplace(newUpper); // replaced...
			S.emplace(newE); // new element...
			
			if (best.second==upper && best.first==0) {
				// update best
				if (newE.right>newE.left) {
					ans=newE.right;
					best.first=1;
				}
				else {
					ans=newE.left;
					best.first=0;
				}
				best.second=S.find(newE);
			}

			S.erase(upper); // replacing it...
		}
		else if (upper==S.end()) {
			lower--;
			newE.right=X-newE.pos;
			newE.left=newE.pos-(*lower).pos;

			const E newLower((*lower).pos,(*lower).left,newE.left);
			S.emplace(newLower); // replaced...
			S.emplace(newE); // new element...

			if (best.second==lower && best.first==1) {
				// update best
				if (newE.right>newE.left) {
					ans=newE.right;
					best.first=1;
				}
				else {
					ans=newE.left;
					best.first=0;
				}
				best.second=S.find(newE);
			}

			S.erase(lower); // replacing it...
		}
		else {
			// in between 2 existing
			lower--;
			newE.right=(*upper).pos-newE.pos;
			newE.left=newE.pos-(*lower).pos;
			
			const E newUpper((*upper).pos,newE.right,(*upper).right);
			const E newLower((*lower).pos,(*lower).left,newE.left);			
			S.emplace(newUpper);
			S.emplace(newLower);
			S.emplace(newE);

			if (best.second==upper && best.first==0) {
				// update best
				if (newE.right>newE.left) {
					ans=newE.right;
					best.first=1;
				}
				else {
					ans=newE.left;
					best.first=0;
				}
				best.second=S.find(newE);
			}
			else if (best.second==lower && best.first==1) {
				// update best
				if (newE.right>newE.left) {
					ans=newE.right;
					best.first=1;
				}
				else {
					ans=newE.left;
					best.first=0;
				}
				best.second=S.find(newE);
			}

			S.erase(upper);
			S.erase(lower);
		}
		cout << ans << ' ';
	}
	cout << endl;
	
}