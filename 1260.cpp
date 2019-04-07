#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, c;
bool visit[1001],visit1[1001];
vector<int> adj[1001];

void dfs(int cur){
	cout << cur<<" ";
	for (int i = 0; i < adj[cur].size(); i++){
		int nxt = adj[cur][i];
		if (!visit[nxt]){
			visit[nxt] = true;
			dfs(nxt);
		}
	}

}

void bfs(int st){
	queue<int> q;
	q.push(st);
	visit1[st] = true;

	while (!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < adj[cur].size(); i++){
			int nxt = adj[cur][i];
			if (!visit1[nxt]){
				q.push(nxt);
				visit1[nxt]=true;
			}
		}
	}
}


int main(){
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++){
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	visit[c] = true;
	dfs(c); cout << '\n';
	bfs(c);
}
