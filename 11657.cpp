#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct pnt {
	int s,e;
	int cost;
};
int n, m;

vector<pnt> vt;
int D[501];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) D[i] = 100000000;

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		vt.push_back({s,e,c });	
	}
	
	D[1] = 0;

	bool cycle = false;

	for (int i = 1; i <= n; i++) {
		for (int next = 0; next < m; next++) {
				if(D[vt[next].s] != 100000000 && D[vt[next].e] > vt[next].cost + D[vt[next].s]) {
					if (i == n) cycle = true;
					else D[vt[next].e] = vt[next].cost + D[vt[next].s]; 
			}
		}
		
	}
	
	if (cycle) cout << -1 << '\n';
	else {
		for (int i = 2; i <= n; i++) {
			if (D[i] == 100000000) cout << -1 << '\n';
			else cout << D[i] << '\n';
		}
	}
}
