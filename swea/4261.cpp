#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const char P[26] =
{
	2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9
};
vector<string> W;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		string S;
		int N;
		cin >> S;
		scanf("%d", &N);
		W = vector<string>(N);
		for(int i=0; i<N; i++)
			cin >> W[i];

		int ret = 0;
		for(int i=0; i<N; i++) {
			string s;
			for(int j=0; j<W[i].size(); j++)
				s.push_back(P[W[i][j]-'a'] + '0');
			if( s == S )
				ret++;
		}
		printf("#%d %d\n", test+1, ret);
	}
}