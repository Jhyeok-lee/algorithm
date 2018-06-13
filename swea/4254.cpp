#include <iostream>

using namespace std;

int N;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d", &N);
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		for(int i=0; i<N; i++) {
			char s[4];
			scanf("%3s", s);
			if( s[0] == '*' ) {
				if( s[1] == '*' ) {
					if( s[2] == '*' )
						continue;
					else
						a = max(a, s[2]-'0');
				}
				else {
					if( s[2] == '*' )
						d = max(d, s[1]-'0');
					else
						a = max(a, s[1]-'0' + s[2]-'0');
				}
			}
			else {
				if( s[1] == '*' ) {
					if( s[2] == '*' )
						c = max(c, s[0]-'0');
					else {
						if( s[0] < s[2] )
							a = max(a, s[2]-'0');
						else
							c = max(c, s[0]-'0');
					}
				}
				else {
					if( s[2] == '*' )
						c = max(c, s[0]-'0' + s[1]-'0');
					else
						b += (s[0]-'0' + s[1]-'0' + s[2]-'0');
				}
			}
		}
		printf("#%d %d\n", test+1, max(d, a+b+c));
	}
}