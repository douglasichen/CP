#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> F('z'+1);
	char c;
	for (int i=0; i<N; i++)	{
		cin>>c;
		F[c]++;	
	}
	int odd=0;
	for (int i : F) odd+=i%2;
	cout << max(odd,1) << endl;
}