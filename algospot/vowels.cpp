#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		char str[1001];
		char s[5] = {'a', 'e', 'i', 'o', 'u'};
		scanf("%d %s", &N, str);
		int start = -2;
		int end = -2;
		int len = 1000;
		for(int i=0; i<N; i++) {
			if( s[0] == str[i] ) {
				int p = 1;
				int j;
				for(j=i+1; j<N; j++) {
					if( s[p] == str[j] )
						p++;
					if( p == 5 )
						break;
				}
				if( p == 5 && len > j-i+1 ) {
					start = i;
					end = j;
					len = j-i+1;
				}
			}
		}
		start++;
		end++;

		printf("Case #%d\n%d %d\n", test+1, start, end);
	}
}