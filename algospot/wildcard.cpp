#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int memo[101][101];
string wildcard;
string target;

int solve(int w, int t)
{
	int& ret = memo[w][t];
	if( ret != -1 )
		return ret;

	if( w < wildcard.size() && t < target.size() &&
		( wildcard[w] == '?' || wildcard[w] == target[t]) ) {
		return ret = solve(w+1, t+1);
	}

	if( w == wildcard.size() )
		return ret = (t == target.size());

	if( wildcard[w] == '*' ) {
		if( solve(w+1,t) || 
			(t < target.size() && solve(w, t+1) ) )
			return ret = 1;
	}

	return 0;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		cin >> wildcard;
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			cin >> target;
			memset(memo, -1, sizeof(memo));
			int check = solve(0,0);
			if( check )
				cout << target + "\n";
		}
	}
	return 0;
}