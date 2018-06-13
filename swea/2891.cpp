#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int up[6][6];
int down[6][6];
bool check[6][6];
bool rowCandidates[6][10];
bool colCandidates[6][10];
bool sqCandidates[3][2][10];

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(check, 0, sizeof(check));
		memset(rowCandidates, 0, sizeof(rowCandidates));
		memset(colCandidates, 0, sizeof(colCandidates));
		memset(sqCandidates, 0, sizeof(sqCandidates));
		for(int i=0; i<6; i++) {
			for(int j=0; j<6; j++) {
				char buf[4];
				scanf("%3s", buf);
				if( buf[1] == '/' ) {
					up[i][j] = (buf[0]!='-')?buf[0]-'0':0;
					down[i][j] = (buf[2]!='-')?buf[2]-'0':0;
				}
				else {
					up[i][j] = (buf[0]!='-')?buf[0]-'0':0;
					down[i][j] = 1;
				}
			}
		}
		printf("#%d\n", test+1);
		for(int i=0; i<6; i++) {
			if( down[i][0] == 1 )
				printf("%d", up[i][0]);
			else
				printf("%d/%d", up[i][0], down[i][0]);
			for(int j=1; j<6; j++) {
				if( down[i][j] == 1 )
					printf(" %d", up[i][j]);
				else
					printf(" %d/%d", up[i][j], down[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}