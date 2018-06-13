#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

char move(char c)
{
	c -= 'A';
	c = (c+1)%3;
	c += 'A';
	return c;
}

bool canMove(string s, int idx)
{
	char c = (s[idx]-'A' + 1)%3 + 'A';
	for(int i=idx-1; i>=0 ;i--) {
		if( s[i] >= c )
			return false;
	}
	return true;
}

int N;
string ss;
map<string, int> m;

void dfs(string s)
{
	if( s == ss )
		return;
	for(int i=0; i<s.size(); i++) {
		if( canMove(s,i) ) {
			string next = s;
			next[i] = move(s[i]);
			if( m.count(next) )
				continue;
			m[next] = 1;
			dfs(next);
		}
	}
}

int main(void)
{
	int Case = 1;
	//scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		m.clear();
		ss.clear();
		//scanf("%d", &N);
		N = 1000000;
		ss.assign(N, 'A');
		string s;
		//cin >> s;
		for(int i=0; i<333333; i++)
			s += "ABC";
		s += 'A';
		dfs(s);
		printf("Case #%d\n", test+1);
		if( m.count(ss) )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}