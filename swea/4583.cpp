#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int M;
		long long K;
		scanf("%d %lld", &M, &K);

		vector<pair<int,int> > change;
		for(int i=0; i<M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			change.push_back(make_pair(a,b));
		}

		vector<int> init;
		vector<int> state;
		for(int i=0; i<7; i++) {
			init.push_back(i);
			state.push_back(i);
		}
		int count = 0;
		map<int, vector<int> > m;
		map<vector<int>, int> mm;
		while( true ) {
			if( mm.count(state) != 0 && count%M == 0 && init == state )
				break;
			m[count] = state;
			mm[state] = count;
			int a = change[count%M].first;
			int b = change[count%M].second;
			swap(state[a-1], state[b-1]);
			count++;
		}

		K %= count;
		vector<int> ret = m[K];
		printf("#%d ", test+1);
		for(int i=0; i<ret.size(); i++)
			printf("%d", ret[i]);
		printf("\n");
	}
	return 0;
}