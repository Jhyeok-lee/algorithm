#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		char str[1001];
		bool cards[4][13] = {0,};
		bool check = false;
		int counting[4] = {0,};
		scanf("%s", str);
		for(int i=0; i<1001; i+=3) {
			char card = str[i];
			int num = (str[i+1]-'0')*10+(str[i+2]-'0')-1;
			if( card == '\0' )
				break;
			if( card == 'S' )
				card = 0;
			else if( card == 'D' )
				card = 1;
			else if( card == 'H' )
				card = 2;
			else if( card == 'C' )
				card = 3;

			if( cards[card][num] ) {
				check = true;
				break;
			}
			else {
				cards[card][num] = true;
				counting[card]++;
			}
		}

		if( check )
			printf("#%d ERROR\n", test+1);
		else
			printf("#%d %d %d %d %d\n", test+1, 13-counting[0], 13-counting[1], 13-counting[2], 13-counting[3]);
	}
	return 0;
}