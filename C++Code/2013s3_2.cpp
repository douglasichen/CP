#include <bits/stdc++.h>
using namespace std;

int fav,g;
vector<int> scores(5);
vector<vector<bool>> played(5,*(new vector<bool>(5)));
vector<vector<int>> notPlayed;

bool favWon(vector<int> sc) {
	vector<int> best={0,-1};
	for (int i=1; i<=4; i++) {
		if (sc[i]>best[1]) {
			best={i,sc[i]};
		}
	}
	for (int i=1; i<=4; i++) {
		if (i==best[0]) continue;
		if (sc[i]==best[1])
			return false;
	}
	return best[0]==fav;
}



vector<int> lose(vector<int> game, vector<int> prevScores) {
	prevScores[game[1]]+=3;
	return prevScores;
}

vector<int> tie(vector<int> game, vector<int> prevScores) {
	prevScores[game[0]]++;
	prevScores[game[1]]++;
	return prevScores;
}

vector<int> win(vector<int> game, vector<int> prevScores) {
	prevScores[game[0]]+=3;
	return prevScores;
}

int solve() {
	if (notPlayed.size()==0)
		return favWon(scores);
	
	int ans=0;
	stack<pair<int,vector<int>>> s;	// game to play index, new scores from prev game played
	s.push({0,scores});

	while (!s.empty()) {
		pair<int,vector<int>> top=s.top(); s.pop();
		int gameIndex=top.first;
		vector<int> prevScores=top.second;

		if (gameIndex<notPlayed.size()) {
			vector<int> game=notPlayed[gameIndex];
			vector<int> lostScores=lose(game,prevScores), tieScores=tie(game,prevScores), winScores=win(game,prevScores);
			s.push({gameIndex+1,lostScores});
			s.push({gameIndex+1,tieScores});
			s.push({gameIndex+1,winScores});
			// cout << game[0] << " " << game[1] << " lost, tie, and won" << endl;
		}
		else {
			// this is the last game
			if (favWon(prevScores)) {
				ans++;
			}
			// else {
			// 	cout << "didnt win!" << endl;
			// }
		}
	}

	return ans;
}

int main() {
	cin>>fav>>g;
	for (int i=0; i<g; i++) {
		int A,B,sA,sB; cin>>A>>B>>sA>>sB;
		played[A][B]=1;
		played[B][A]=1;
		if (sA==sB) {
			scores[A]++;
			scores[B]++;
		}
		else {
			if (sA>sB)
				scores[A]+=3;
			else
				scores[B]+=3; 
		}
	}
	
	for (int y=1; y<=4; y++) {
		for (int x=1; x<=4; x++) {
			if (x==y) continue;
			if(!played[y][x])	
			notPlayed.push_back({y,x});
			played[y][x]=1;
			played[x][y]=1;
		}
	}
	
	// cout << "not played: " << endl;
	// for (vector<int> game : notPlayed) {
	// 	cout << "game: " << game[0] << ' ' << game[1] << endl;
	// }

	int ans=solve();
	cout << ans << endl;
	
}