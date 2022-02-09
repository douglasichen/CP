#include <bits/stdc++.h>
using namespace std;

int nums[3][3];
bool unk[3][3];

// void print2d(int a[3][]) {
// 	for (int y=0; y<3; y++) {
// 		for (int x=0; x<3; x++)
// 			cout << a[y][x] << " ";
// 		cout << endl;
// 	}
// 	cout << endl;
// }

int getNotUnkCnt() {
	int ans=0;
	for (int y=0; y<3; y++)
		for (int x=0; x<3; x++)
			ans+=!unk[y][x];
	return ans;
}

int getUnkCount() {
	int ans=0;
	for (int y=0; y<3; y++)
		for (int x=0; x<3; x++)
			ans+=unk[y][x];
	return ans;
}

bool work(int a[], vector<int> b) {
	if (a[0]==b[0]) {
		bool have[3];
		have[a[1]]=1;
		have[b[1]]=1;

		int missing=0;
		for (int x=0; x<3; x++) {
			if (!have[x]) {
				missing=x;
				break;
			}
		}
		if (missing==1) {
			return (( nums[a[0]][a[1]]+nums[b[0]][b[1]] ) & 1) != 1;
		}
	}
	else {
		bool have[3];
		have[a[0]]=1;
		have[b[0]]=1;

		int missing=0;
		for (int y=0; y<3; y++) {
			if (!have[y]) {
				missing=y;
				break;
			}
		}
		if (missing==1) {
			return (( nums[a[0]][a[1]]+nums[b[0]][b[1]] ) & 1) != 1;
		}
	}
	return true;
}

void calc1() {
	//rows
	for (int y=0; y<3; y++) {
		int unkXCnt=0;
		int unkX=0;
		for (int x=0; x<3; x++) {
			if (unk[y][x]) {
				unkXCnt++;
				unkX=x;
			}
		}
		if (unkXCnt==1) {
			switch (unkX) {
				case 0:
				nums[y][unkX]=nums[y][1]+(nums[y][1]-nums[y][2]);
				break;
				case 1:
				nums[y][unkX]=(nums[y][0]+nums[y][2])/2;
				break;
				case 2:
				nums[y][unkX]=nums[y][1]+(nums[y][1]-nums[y][0]);
				break;
			}
			unk[y][unkX]=0;
		}
	}
	
	//cols
	for (int x=0; x<3; x++) {
		int unkYCnt=0;
		int unkY=0;
		for (int y=0; y<3; y++) {
			if (unk[y][x]) {
				unkYCnt++;
				unkY=y;
			}
		}
		if (unkYCnt==1) {
			switch (unkY) {
				case 0:
				nums[unkY][x]=nums[1][x]+(nums[1][x]-nums[2][x]);
				break;
				case 1:
				nums[unkY][x]=(nums[0][x]+nums[2][x])/2;
				break;
				case 2:
				nums[unkY][x]=nums[1][x]+(nums[1][x]-nums[0][x]);
				break;
			}
			unk[unkY][x]=0;
		}
	}
}

void calc2() {
	int cnt=getNotUnkCnt();
	if (cnt==1) {
		int val=0;
		bool good=0;
		for (int y=0; y<3; y++) {
			for (int x=0; x<3; x++) {
				if (!unk[y][x]) {
					val=nums[y][x];
					good=1;
					break;
				}
			}
			if (good) break;
		}
		for (int y=0; y<3; y++)
			for (int x=0; x<3; x++)
				nums[y][x]=val;
		memset(unk,0,sizeof unk);
	}
	else if (cnt==2) {
		int a[2],b[2];
		memset(a,-1,sizeof a);
		memset(b,-1,sizeof b);
		bool good=0;
		for (int y=0; y<3; y++) { 
			for (int x=0; x<3; x++) {
				if (!unk[y][x]) {
					if (a[0]==-1) {
						a[0]=y;
						a[1]=x;
					}
					else {
						b[0]=y;
						b[1]=x;
						good=1;
						break;
					}
				}
			}
			if (good) break;
		}
		// cout << "a: " << a[0] << " " << a[1] << endl;
		// cout << "b: " << b[0] << " " << b[1] << endl;

		bool work1=work(a, {a[0],b[1]});
		if (work1) {
			for (int y=0; y<3; y++) {
				nums[y][a[1]]=nums[a[0]][a[1]];
				nums[y][b[1]]=nums[b[0]][b[1]];
				unk[y][a[1]]=0;
				unk[y][b[1]]=0;
			}
		}
		else {
			for (int x=0; x<3; x++) {
				nums[a[1]][x]=nums[a[0]][a[1]];
				nums[b[1]][x]=nums[b[0]][b[1]];
				unk[a[1]][x]=0;
				unk[b[1]][x]=0;
			}
		}
		calc1();
		calc1();

	}
	else if (cnt==3) {
		bool sameX=0, sameY=0;
		vector<int> ys, xs;
		for (int y=0; y<3; y++) {
			for(int x=0; x<3; x++) {
				if (!unk[y][x]) {
					ys.push_back(y);
					xs.push_back(x);
				}
			}
		}
		sameX=(xs[0]==xs[1] && xs[0]==xs[2]);
		sameY=(ys[0]==ys[1] && ys[0]==ys[2]);
		bool sameLevel=(sameX||sameY);

		if (sameLevel) {
			// cout << "going into i have..." << endl;
			// for (int y=0; y<3; y++) {
			// 	for (int x=0; x<3; x++) {
			// 		cout << nums[y][x] << ' '; 
			// 	}
			// 	cout << endl;
			// }
			if (sameX) {
				for (int y=0; y<3; y++) {
					for (int x=0; x<3; x++) {
						nums[y][x]=nums[y][xs[0]];
						unk[y][x]=0;
					}
				}
			}
			else {
				for (int x=0; x<3; x++) {
					for (int y=0; y<3; y++) {
						nums[y][x]=nums[ys[0]][x];
						unk[y][x]=0;
					}
				}
			}
		}
		else {
			int series[3];
			for (int y=0; y<3; y++) {
				for (int x=0; x<3; x++) {
					if (!unk[y][x]) {
						series[y]=nums[y][x];
						break;
					}
				}
			}

			cout << "series: ";
			for (int i=0; i<3; i++) cout << series[i] << " ";
			cout << endl;

			int d1=series[1]-series[0], d2=series[2]-series[1];
			// cout << d1 << " vs " << d2 << endl;
			if (d1==d2) {
				for (int y=0; y<3; y++) {
					for (int x=0; x<3; x++) {
						if (!unk[y][x]) {
							for (int i=0; i<3; i++)
								nums[y][i]=nums[y][x];
							break;
						}
					}
				}
			}
			else {
				for (int x=0; x<3; x++) {
					for (int y=0; y<3; y++) {
						if (!unk[y][x]) {
							for (int i=0; i<3; i++)
								nums[i][x]=nums[y][x];
							break;
						}
					}
				}
			}
		}
	}
	else if (cnt==5) {
		unk[1][1]=0;
		calc1();
		calc1();
		calc1();
	}
	
}

int main() {
	memset(nums,0,sizeof nums);
	memset(unk,0,sizeof unk);
	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			string s; cin>>s;
			if (s=="X")
				unk[y][x]=1;
			else
				nums[y][x]=stoi(s);
		}
	}
	
	calc1();
	calc1();

	if (getUnkCount()!=0) {
		calc2();
		// calc2();
	}
	calc1();
	calc1();

	// print answer
	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			if (unk[y][x])
				cout << "X ";
			else
				cout << nums[y][x] << ' ';
		}
		cout << endl;
	}
}