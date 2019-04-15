// https://github.com/sol2namu/BOJ 
// 문제 푼 사람 : sol2namu

const int MAX = 52;
const int INF = 1000000000;

int c[MAX][MAX]; 
int f[MAX][MAX]; 

int ans;
int n;
vector<int> adj[MAX];

inline int ctol(char c){
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

void networkFlow(){
	int total = 0, S = ctol('A'), E = ctol('Z');

	while (1){
		int prv[MAX];
		memset(prv, -1, sizeof(prv));

		queue<int> q;
		q.push(S);
		
		while (!q.empty() && prv[E] == -1){
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++){
				int nxt = adj[cur][i];

				if (c[cur][nxt] - f[cur][nxt] > 0 && prv[nxt] == -1){
					q.push(nxt);
					prv[nxt] = cur;
					if (nxt == E) break;

				}
			}
		}
		
		if (prv[E] == -1) break;

		int w = INF;
		for (int i = E; i != S; i = prv[i])
			w = min(w, c[ prv[i] ][ i ] - f[ prv[i] ][ i ]);

		for (int i = E; i != S; i = prv[i]){
			f[prv[i]][i] += w;
			f[i][prv[i]] -= w;
		}
		
		ans += w;
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		char to, from;
		int cost;
		cin >> to >> from >> cost;

		int u = ctol(to),v= ctol(from);
	
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = c[v][u] += cost;
	}
	networkFlow();
	cout << ans;
}
