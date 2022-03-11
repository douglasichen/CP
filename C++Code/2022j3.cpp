#include <bits/stdc++.h>
using namespace std;

bool isNum(char c) {
	return c>='0' && c<='9';
}

int main() {
	// grouping the notes and pitch change characters.
	string s; cin>>s;
	string ans="", group="", sVal="";
	bool lookVal=false;					// whether to group numbers
	int type=1;							// positive or negative
	for (char c : s) {
		// if there is a + or -, start grouping number characters
		if (c=='+' || c=='-') {
			type=(c=='+' ? 1 : -1);
			lookVal=true;
		}
		else {
			if (!lookVal)
				group.push_back(c);
			else {
				if (isNum(c))
					sVal.push_back(c);
				else {
					// print data
					cout << group << (type==1 ? " tighten " : " loosen ") << stoi(sVal) << endl;

					// reset
					group="";
					group.push_back(c);
					sVal="";
					lookVal=false;
				}
			}
		}
	}
	// print data
	cout << group << (type==1 ? " tighten " : " loosen ") << stoi(sVal) << endl;
}