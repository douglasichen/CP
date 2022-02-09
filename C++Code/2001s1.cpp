#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
	string s; cin>>s;
	string C="",D="",H="",S="";
	int pC=0,pD=0,pH=0,pS=0;
	char suit=s[0];
	for (char c : s) {
		if (c=='C' || c=='D' || c=='H' || c=='S') {
			suit=c;
			continue;
		}
		switch(suit) {
			case 'C':
			C+=c;
			break;
			case 'D':
			D+=c;
			break;
			case 'H':
			H+=c;
			break;
			case 'S':
			S+=c;
			break;
		}
	}
	for (char c : C) {
		switch (c) {
			case 'A':
			pC+=4;
			break;
			case 'K':
			pC+=3;
			break;
			case 'Q':
			pC+=2;
			break;
			case 'J':
			pC+=1;
			break;
		}
	}
	for (char c : D) {
		switch (c) {
			case 'A':
			pD+=4;
			break;
			case 'K':
			pD+=3;
			break;
			case 'Q':
			pD+=2;
			break;
			case 'J':
			pD+=1;
			break;
		}
	}
	for (char c : H) {
		switch (c) {
			case 'A':
			pH+=4;
			break;
			case 'K':
			pH+=3;
			break;
			case 'Q':
			pH+=2;
			break;
			case 'J':
			pH+=1;
			break;
		}
	}
	for (char c : S) {
		switch (c) {
			case 'A':
			pS+=4;
			break;
			case 'K':
			pS+=3;
			break;
			case 'Q':
			pS+=2;
			break;
			case 'J':
			pS+=1;
			break;
		}
	}
	switch(C.size()) {
		case 0:
		pC+=3;
		break;
		case 1:
		pC+=2;
		break;
		case 2:
		pC++;
		break;
	}
	switch(D.size()) {
		case 0:
		pD+=3;
		break;
		case 1:
		pD+=2;
		break;
		case 2:
		pD++;
		break;
	}
	switch(H.size()) {
		case 0:
		pH+=3;
		break;
		case 1:
		pH+=2;
		break;
		case 2:
		pH++;
		break;
	}
	switch(S.size()) {
		case 0:
		pS+=3;
		break;
		case 1:
		pS+=2;
		break;
		case 2:
		pS++;
		break;
	}


	cout << "Cards Dealt Points" << endl;
	
	cout << "Clubs ";
	for (char c : C) cout << c << " ";
	cout << pC << endl;

	cout << "Diamonds ";
	for (char c : D) cout << c << " ";
	cout << pD << endl;
	
	cout << "Hearts ";
	for (char c : H) cout << c << " ";
	cout << pH << endl;
	
	cout << "Spades ";
	for (char c : S) cout << c << " ";
	cout << pS << endl;
	
	cout << "Total " << pC+pD+pH+pS << endl;

}