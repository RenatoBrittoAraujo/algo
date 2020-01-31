#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string &s, string &t, vector<int> &lps)
{
	vector<int> rep;
	int lindx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (lindx > 0 and t[lindx] != s[i]) 
			lindx = lps[lindx - 1];
		if (t[lindx] == s[i])
		{
			lindx++;
			if (lindx == lps.size()) {
			      	lindx--;
	       			rep.push_back(i - t.size() + 1);
			}
		}
	}

	return rep;
}

vector<int> lps(string &t)
{
	vector<int> vlps(t.size(), 0);
	for (int i = 1; i < (int) t.size(); i++)
	{
		if (t[vlps[i - 1]] == t[i]) 
			vlps[i] = vlps[i - 1] + 1;
		else {
			int p = i - 1;
			while (p > 0 and t[vlps[p - 1]] != t[i]) {
				p = vlps[p - 1];
			}
			vlps[i] = vlps[p];
		}	
	}
	return vlps;
}

int main()
{
	string s, t;
	cin>>s>>t;
	auto vlps = lps(t);
	auto vkmp = kmp(s, t, vlps);
}

