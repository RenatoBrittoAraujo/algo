#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
const int N = 1e5 + 10;

int vis[N];
bool cycle(int u, int p)
{
	vis[u] = 1;
	for (auto v : G[u])
		if (vis[v] and v != p)
			return true;
		else if (!vis[v])
			if (cycle(v, u))
				return true;
	return false;
}

int main()
{
	int v, e;
	cin>>v>>e;
	G.resize(v);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool cycle_detected = false;
	for (int i = 0; i < v; i++)
		if (!vis[i])
			cycle_detected |= cycle(i, -1);
	cout<<(cycle_detected ? "Has cycle" : "Does not have cycle")<<endl;
}
