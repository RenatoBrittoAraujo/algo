#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string &s, string &t, vector<int> &lps)
{
	vector<int> rep;
	
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
	cout<<"LPS: ";
	for (auto v : vlps) cout<<v<<' ';
	cout<<endl;
	auto vkmp = kmp(s, t, vlps);
	cout<<"MATCHES: ";
	for (auto v : vkmp) cout<<v<<' ';
	cout<<endl;
	
}

