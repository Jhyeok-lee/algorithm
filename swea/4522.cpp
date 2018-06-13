#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		string s;
		cin >> s;
		bool ret = true;
		for(int i=0; i<s.size()/2; i++) {
			if( s[i] == '?' || s[s.size()-i-1] == '?' )
				continue;
			else if( s[i] == s[s.size()-i-1] )
				continue;
			else {
				ret = false;
				break;
			}
		}
		printf("#%d ", test+1);
		if( !ret )
			printf("Not exist\n");
		else
			printf("Exist\n");
	}
	return 0;
}