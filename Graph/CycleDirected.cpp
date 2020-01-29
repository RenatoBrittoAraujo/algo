#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
const int N = 1e5 + 10;

int vis[N];
bool cycle(int u)
{
	if (vis[u] == 2) return false;
	if (vis[u] == 1) return true;
	vis[u] = 1;
	bool ans = false;
	for (auto v : G[u])
		ans |= cycle(v);
	vis[u] = 2;
	return ans;
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
	}
	bool cycle_detected = false;
	for (int i = 0; i < v; i++)
		cycle_detected |= cycle(i);
	cout<<(cycle_detected ? "Has cycle" : "Does not have cycle")<<endl;
}
