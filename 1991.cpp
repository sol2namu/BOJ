#include<iostream>
using namespace std;

char node[26][2];
int n;
void preOrder(int NODE){
	cout << char(NODE + 'A');
	if(node[NODE][0]!=-1) preOrder(node[NODE][0]);
	if (node[NODE][1] != -1)preOrder(node[NODE][1]);
}

void inOrder(int NODE){
	if (node[NODE][0] != -1) inOrder(node[NODE][0]);
	cout << char(NODE + 'A');
	if (node[NODE][1] != -1)inOrder(node[NODE][1]);
}

void postOrder(int NODE){
	if (node[NODE][0] != -1) postOrder(node[NODE][0]);
	if (node[NODE][1] != -1) postOrder(node[NODE][1]);
	cout <<char( NODE + 'A');
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++){
		char root, left, right;
		cin >> root >> left >> right;
		node[root-'A'][0] = (left != '.')? left-'A' : -1 ;
		node[root - 'A'][1] = (right != '.') ? right - 'A' : -1;

	}
	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
}
