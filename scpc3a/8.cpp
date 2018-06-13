#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N,M;
int switchCount;
int rSwitchNum[100][100];
int cSwitchNum[100][100];
int sw[20000][3];
vector<vector<int> > graph;
int sccId[40000];
int discovered[40000];
stack<int> st;
int sccCounter;
int vertexCounter;
vector<int> ret;
int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for(int i=0; i<graph[here].size(); i++) {
		int there = graph[here][i];
		if( discovered[there] == -1 )
			ret = min(ret, scc(there));
		else if( sccId[there] == -1 )
			ret = min(ret, discovered[there]);
	}

	if( ret == discovered[here] ) {
		while(true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if( t == here )
				break;
		}
		sccCounter++;
	}
	return ret;
}

int cSwitchSet(int j, int b)
{
	if( cSwitchNum[j][b] == -1 ) {
		cSwitchNum[j][b] = switchCount;
		sw[switchCount][0] = 1;
		sw[switchCount][1] = j;
		sw[switchCount][2] = b;
		switchCount++;
	}
	return cSwitchNum[j][b];
}

int rSwitchSet(int i, int a)
{
	if( rSwitchNum[i][a] == -1 ) {
		rSwitchNum[i][a] = switchCount;
		sw[switchCount][0] = 0;
		sw[switchCount][1] = i;
		sw[switchCount][2] = a;
		switchCount++;
	}
	return rSwitchNum[i][a];
}

int main(void)
{
	//setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		switchCount = 0;
		vertexCounter = 0;
		sccCounter = 0;
		memset(rSwitchNum, -1, sizeof(rSwitchNum));
		memset(cSwitchNum, -1, sizeof(cSwitchNum));
		memset(sccId, -1, sizeof(sccId));
		memset(discovered, -1, sizeof(discovered));
		memset(sw, 0, sizeof(sw));
		ret.clear();
		graph = vector<vector<int> >(40000);
		while( !st.empty() )
			st.pop();

		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				int on,a,b;
				scanf("%d %d %d", &on, &a, &b);
				int rNum = rSwitchSet(i,a);
				int cNum = cSwitchSet(j,b);
				if( on ) {
					graph[rNum*2].push_back(cNum*2);
					graph[cNum*2].push_back(rNum*2);
					graph[rNum*2+1].push_back(cNum*2+1);
					graph[cNum*2+1].push_back(rNum*2+1);
				}
				else {
					graph[rNum*2].push_back(cNum*2+1);
					graph[cNum*2].push_back(rNum*2+1);
					graph[rNum*2+1].push_back(cNum*2);
					graph[cNum*2+1].push_back(rNum*2);
				}
			}
		}
		for(int i=0; i<switchCount*2; i++) {
			if( discovered[i] == -1 )
				scc(i);
		}

		int r = 1;
		int n = switchCount;
		vector<pair<int,int> > order;
		for(int i=0; i<n; i++) {
			if(sccId[i*2] == sccId[i*2+1]) {
				r = 0;
				break;
			}
			order.push_back(make_pair(-sccId[i*2], i*2));
			order.push_back(make_pair(-sccId[i*2+1], i*2+1));
		}
		printf("Case #%d\n", test+1);
		if( r ) {
			ret = vector<int>(n,-1);
			sort(order.begin(), order.end());

			for(int i=0; i<order.size(); i++) {
				int vertex = order[i].second;
				int variable = vertex/2;
				int isTrue = (vertex&1);
				if( ret[variable] != -1 )
					continue;
				ret[variable] = isTrue;
			}
			for(int i=0; i<ret.size(); i++) {
				if( ret[i] == 1 ) {
					if( sw[i][0] )
						printf("C%02d%02d ", sw[i][1], sw[i][2]);
					else
						printf("R%02d%02d ", sw[i][1], sw[i][2]);
				}
			}
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	return 0;
}