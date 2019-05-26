#include<iostream>
#include<string>
using namespace std;

int Acnt[26], Bcnt[26];

int ans = 0;

int main(){
	string A,B;
	cin >> A>>B;
	
	for (int i = 0; i < B.length(); i++){
		Bcnt[B.at(i) - 'A']++;
	}

	for (int i = 0; i <= A.length()-B.length(); i++){
		for (int j = 0; j < 26; j++) Acnt[j] = 0;
		for (int j = i; j < i + B.length(); j++){
			Acnt[A.at(j) - 'A']++;
		}

		bool flag = true;
		for (int j = 0; j < 26; j++){
			if (Acnt[j] != Bcnt[j]) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}
	cout << ans;
}
