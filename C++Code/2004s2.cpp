#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


void solve() {

}



bool sorter(pi a, pi b) {
	return a.S > b.S;
}


int getRank(int n, vector<vector<pi>> v, int round) {
	vector<pi> roundScores = v[round];
	sort(roundScores.begin(), roundScores.end(), sorter);
	for (int i=0; i<roundScores.size(); i++) if (roundScores[i].F==n) return i;
	return -1;
}


int main() {
	

	int n, k; cin>>n>>k;
	vi map(n);
	vector<vector<pi>> v(k);

	for (int i=0; i<k; i++) {
		for (int o=0; o<n; o++) v[i].PB({o,0});
	}
	// for (int i=0; i<n; i++) map[i].F = i;

	pi best = {-1,-2000};
	int bestWorstRank = n;
	
	for (int i=0; i<k; i++) {
		for (int o=0; o<n; o++) {
			int score; cin>>score;
			map[o]+=score;			
			v[i][o].S = score;
			if (map[o] > best.S) {
				best = {o,map[o]};
			}
		}
	}

	int worstRank = 0;
	for (int i=0; i<v.size(); i++) {
		int rank = getRank(best.F, v, i);
		// cout << "rank: "<< rank<<endl;
		if (rank > worstRank) worstRank = rank;
	}

	cout << "Yodeller "<<best.F+1 <<" is the TopYodeller: score "<<best.S<<", worst rank "<<worstRank+1<<endl;
}