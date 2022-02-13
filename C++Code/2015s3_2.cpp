#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	int g,p; cin>>g>>p;

	unordered_map<int,bool> needed;
	vector<int> planes(p);
	for (int i=0; i<p; i++) {
		cin>>planes[i];
		needed[planes[i]]=1;
	}

	vector<bool> taken(g+1);
	vector<int> offsets(g+1);
	for (int gateLoc : planes) {
		int offset=offsets[gateLoc];

		// pull down
		int loc=gateLoc;
		while (offset>0) {
			loc-=offset;
			offset=offsets[loc];
			
			// if u meet a gate that is needed while being pulled back then
			if (needed[loc]) {
				offsets[loc]++;
			}
		}
		if (gateLoc<=0) break;
		
		// increase the offset
		offsets[gateLoc]++;
	}
}