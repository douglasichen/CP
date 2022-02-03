#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


int favTeam;

void print2dV(vector<vi> v) {
	for (int i=0; i<v.size(); i++) {
		for (int o=0; o<v[i].size(); o++) {
			cout<<v[i][o]<<' ';
		}
		cout<<endl;
	}
}

void printPiV(vector<pi> v) {
	for (int i=0; i<v.size(); i++) {
		cout<<v[i].F<<' '<<v[i].S;
		if (i!=v.size()-1) cout<<", ";
	}
	cout<<endl;
}

vector<pi> getGamesToPlay(vector<vi> playedWho) {
	vector<pi> notPlayed;
	for (int i=1; i<4; i++) {
		if (!playedWho[0][i]) notPlayed.PB({0,i});
	}
	for (int i=2; i<4; i++) {
		if (!playedWho[1][i]) notPlayed.PB({1,i});
	}
	if (!playedWho[2][3]) notPlayed.PB({2,3});
	return notPlayed;
}

// vector<vi> getOutcomes(vector<pi> toPlay) {
// 	vector<vi> outcomes;

// }

int getWinningTeam(vi score) {
	int biggest=0;
	int winning=0;
	for (int i=0; i<4; i++) {
		if (score[i]>biggest) {
			biggest=score[i];
			winning=i;
		}
	}
	return winning;
}

vector<vi> findPerms(int gamesToPlay) {
	int gameType=0;
	int size = pow(3,gamesToPlay);
	vector<vi> perms(size,*(new vi(gamesToPlay)));
	for (int one=0; one<gamesToPlay; one++) {
		int levelRep = pow(3,one);
		for (int two=0; two<size/(levelRep); two++) {
			// cout<<"two: "<<two<<endl;
			for (int thr=0; thr<levelRep; thr++) {
				perms[two*levelRep+thr][one] = gameType;
			}
			gameType++;
			if (gameType>=3) gameType=0;
			
		}
		gameType=0;
	}
	// print2dV(perms);
	return perms;
}

int main() {
	vector<vi> playedWho(3,(*new vi(4)));
	vi score(4);
	cin>>favTeam; favTeam-=1;
	int playedGames; cin>>playedGames;
	for (int i=0; i<playedGames; i++) {
		int teamA; cin>>teamA; teamA-=1;
		int teamB; cin>>teamB; teamB-=1;
		int scoreA, scoreB; cin>>scoreA>>scoreB;
		if (teamA<3) playedWho[teamA][teamB]=1;
		else playedWho[teamB][teamA]=1;

		if (scoreA>scoreB) score[teamA]+=3;
		else if (scoreB>scoreA) score[teamB]+=3;
		else {
			score[teamA]++;
			score[teamB]++;
		}

	}
	int gamesLeft=6-playedGames;
	vector<pi> toPlay = getGamesToPlay(playedWho);
	// cout<<"winning: "<<winningTeam<<endl;
	// cout<<"score: ";
	// for (int i=0; i<4; i++) cout<<score[i]<<' ';
	// cout<<endl;

	int totalOutcomes = pow(3,gamesLeft);
	// cout<<totalOutcomes<<endl;
	
	// cout<<"to play: ";
	// printPiV(toPlay);
	
	vector<vi> perms = findPerms(gamesLeft);

	int chances = 0;
	vi pastScore = score;
	for (int i=0; i<perms.size(); i++) {
		vi perm = perms[i];
		for (int j=0; j<perm.size(); j++) {
			int type = perm[j];
			if (type==1) {
				score[toPlay[j].F]+=3;
			}
			else if (type==2) {
				score[toPlay[j].S]+=3;
			}
			else {
				score[toPlay[j].F]++;
				score[toPlay[j].S]++;
			}
		}
		bool won = true;
		for (int o=0; o<score.size(); o++) {
			if (o==favTeam) continue;
			if (score[o]>=score[favTeam]) {
				won = false;
				break;
			}
		}
		if (won) chances++;
		score = pastScore;
	}
	cout<<chances<<endl;
	// SOLVED
}