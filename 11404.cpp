#include<iostream>
#include<algorithm>
using namespace std;

typedef struct pnt {
	int idx;
	int cost;
};

int n, m;
int D[106][107];

void f() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) D[i][j] = 0;
			else  D[i][j] = 1000000;
		}
	}

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >>  s>> e >> c;
		if (D[s][e]) {
			if(D[s][e]>c)
				D[s][e] = c;
		}
		else
			D[s][e] = c;
	}

	f();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (D[i][j] == 1000000) D[i][j] = 0;
			cout << D[i][j] << " ";
		}
		cout << '\n';
	}
}
