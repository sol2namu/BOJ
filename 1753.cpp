#include<bits/stdc++.h>
using namespace std;
int v, k, e;
typedef struct p {
	int cost;
	int idx;
};
vector<p> node[20001];
int D[20001];
bool visit[20001];
bool operator<(p a, p b) {
	return a.cost < b.cost;
}

void dijkstra(int init){
	priority_queue<p> pq;
	pq.push({ 0,init });

	while (!pq.empty()){
		int cost = -pq.top().cost;
		int start = pq.top().idx;
		pq.pop();
		if (visit[start]) continue;
		visit[start] = true;
		for (int i = 0; i < node[start].size(); i++){
			int next = node[start][i].idx;
			int w = node[start][i].cost;

			if (D[next] > D[start] + w){
				D[next] = D[start] + w;
				pq.push({ -D[next],next });
			}

		}
	}
}

int main() {
	scanf("%d %d", &v, &e);
	scanf("%d", &k);

	for (int i = 1; i <= v; i++) D[i] = 987654321;

	for (int i = 0; i < e; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		node[s].push_back({ c,e });
	}
	D[k] = 0;
	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (D[i] == 987654321) cout << "INF" << '\n';
		else cout << D[i] << '\n';
	}
}
