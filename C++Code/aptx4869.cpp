#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; cin>>S;
	string E="",LM="";
	unordered_map<string,long long> cnts;
	long long M=1;
	stack<int> BM;
	for (int i=S.size()-1; i>=0; i--) {
		char c=S[i];
		if (isdigit(S[i])) {
			LM+=c;
		}
		else if (isalpha(S[i])) {
			E+=c;
			if (isupper(c)) { // this element is fully named and can add the count
				reverse(E.begin(),E.end());
				reverse(LM.begin(),LM.end());
				int amount=(LM.size() ? stoi(LM) : 1);
				cnts[E]+=M*amount;

				E="",LM="";
			}
		}
		else if (c==')') {
			reverse(LM.begin(),LM.end());
			int amount=(LM.size() ? stoi(LM) : 1);
			M*=amount;
			BM.push(amount);
			LM="";
		}
		else if (c=='(') {
			M/=BM.top(); BM.pop();
		}
	}
	vector<pair<string,long long>> ans;
	for (auto e : cnts) ans.push_back(e);
	sort(ans.begin(),ans.end());
	for (auto e : ans) {
		cout << e.first;
		if (e.second>1) cout << e.second;
	}
	cout << endl;


}