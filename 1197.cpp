#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef struct Node
{
	int start;
	int end;
	int cost;
};
int p[10001];
Node node[100001];
int find_set(int x)
{
	if (p[x] == x) return x;
	else return p[x]=find_set(p[x]);
}
void union_set(int x, int y) //개선
{
	x = p[x];
	y = p[y];
	p[x] = y;
}
bool cmp (const Node &a, const Node &b)
{
	return a.cost < b.cost;
}
int main()
{
	int v, e;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) p[i] = i;
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &node[i].start, &node[i].end, &node[i].cost);
	}

	sort(node, node + e,cmp);

	int cnt = 0, j = 0;
	long long int ans = 0;
	while (1)
	{
		if (cnt == v - 1)
		{
			break;
		}

		if (find_set(node[j].start) != find_set(node[j].end))
		{
			union_set(node[j].start, node[j].end);
			
			ans += node[j].cost;
			cnt++;
		}
		j++;
	}
	printf("%lld",ans);
}
