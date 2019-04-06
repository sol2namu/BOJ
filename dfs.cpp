#include<iostream>
#include<vector>
using namespace std;
int n,m;

vector<int> adj[10];
int visit[16];

void solve(int cur){
	visit[cur] = true;
	cout << cur << " ";
	
	for (int i = 0; i < adj[cur].size(); i++){
		int next = adj[cur][i];
		if (!visit[next]) solve(next);
	}
}

int main(){
	cin >> n>>m;
	for (int i = 0; i < m; i++){
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	solve(0);
}
