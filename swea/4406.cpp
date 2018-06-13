#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		char str[52];
		scanf("%s", str);
		printf("#%d ", test+1);
		for(int i=0; i<51; i++) {
			if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
				str[i] =='o' || str[i] == 'u')
				continue;
			else
				printf("%c", str[i]);
			if( str[i] == '\0' )
				break;
		}
		printf("\n");
	}
	return 0;
}