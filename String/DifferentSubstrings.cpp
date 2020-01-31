#include <bits/stdc++.h>
using namespace std;

// WORKS IN O(N²)

vector<int> pf(string t)
{
	vector<int> lps(t.size(), 0);
	for (int i = 1; i < (int) t.size(); i++)
	{
		if (t[i] == t[lps[i - 1]]) {
			lps[i] = lps[i - 1] + 1;
		} else {
			int p = i;
			while (p > 0 and t[lps[p - 1]] != t[i]) {
				p = lps[p - 1];
			}
			lps[i] = p;
		}
	}
	return lps;
}

int differentsubstrings(string s)
{
	assert(s.size() > 0);
	int k = 1;
	string t = s.substr(0, 1);
	for (int i = 1; i < s.size(); i++)
	{
		t = s.substr(0, i + 1);
		reverse(t.begin(), t.end());
		auto v = pf(t);
		int mx = 0;
		for (auto vx : v) mx = max(mx, vx);
		k += t.size() - mx;
	}
	return k;
}

int main()
{
	string s;
	cin>>s;
	cout<<"Number of different substrings = "
		<<differentsubstrings(s)<<endl;
}
