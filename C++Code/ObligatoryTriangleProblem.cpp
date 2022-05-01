#include <bits/stdc++.h>
using namespace std;

float getAng(int x, int y) {
	return atan2(y,x);
}

float rad2deg(float radian) {
    return(radian * (180 / M_PI));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N,P; cin>>N>>P;
	P%=360;
	pair<float,int> ans={FLT_MAX,0};

	vector<float> V;
	for (int i=0; i<N; i++) {
		int X,Y; cin>>X>>Y;

		float angle=rad2deg(getAng(X,Y)), fP=(float)P;
		float d1=abs(angle-fP), d2=abs(angle+360-fP);
		float dif=min(d1,d2);
		V.push_back(dif);
	}
	for (int i=0; i<N; i++) {
		float dif=V[i];
		if (dif<ans.first) ans={dif,i+1};
	}

	cout << ans.second << endl;
}