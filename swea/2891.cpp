#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class State {
public:
	int a[6][6];
	int b[6][6];
	bool p[6][6];
	bool finish[6][6];
	int count;

	State()
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(p,0,sizeof(finish));
		memset(finish,0,sizeof(finish));
		count = 0;
	}
};

bool isFinish(State& s, int& r, int& c)
{
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			if( !s.finish[i][j] ) {
				r = i;
				c = j;
				return false;
			}
		}
	}
	return true;
}

vector<int> cand(State& s, int r, int c)
{
	bool check[10] = {0,};
	for(int i=0; i<6; i++) {
		int a = s.a[r][i];
		int b = s.b[r][i];
		int cc = s.a[i][c];
		int d = s.b[i][c];
		check[a] = true;
		check[b] = true;
		check[cc] = true;
		check[d] = true;
	}

	int x = r - r%2;
	int y = c - c%3;
	for(int i=x; i<x+2; i++) {
		for(int j=y; j<y+3; j++) {
			int a = s.a[i][j];
			int b = s.b[i][j];
			check[a] = true;
			check[b] = true;
		}
	}

	vector<int> ret;
	for(int i=1; i<=9; i++) {
		if( !check[i] )
			ret.push_back(i);
	}
	return ret;
}

class CMP {
public:
	bool operator() (State& l, State& r)
	{
		return l.count < r.count;
	}
};

State search(State start)
{
	priority_queue<State, vector<State>,  CMP> pq;
	pq.push(start);
	State ret;
	while( !pq.empty() ) {
		State here = pq.top();
		pq.pop();

		int r,c;
		if( isFinish(here,r,c) )
			return here;

		vector<int> ca = cand(here, r, c);
		if( ca.size() == 0 )
			continue;

		if( !here.p[r][c] ) {
			for(int i=0; i<ca.size(); i++) {
				State there = here;
				there.a[r][c] = ca[i];
				there.finish[r][c] = true;
				there.count++;
				pq.push(there);
			}
		}
		else if( here.p[r][c] && !here.a[r][c] && here.b[r][c] ) {
			for(int i=0; i<ca.size(); i++) {
				if( ca[i] > here.b[r][c] )
					continue;
				State there = here;
				there.a[r][c] = ca[i];
				there.finish[r][c] = true;
				there.count++;
				pq.push(there);
			}
		}
		else if( here.p[r][c] && here.a[r][c] && !here.b[r][c] ) {
			for(int i=0; i<ca.size(); i++) {
				if( ca[i] < here.a[r][c] )
					continue;
				State there = here;
				there.b[r][c] = ca[i];
				there.finish[r][c] = true;
				there.count++;
				pq.push(there);
			}
		}
		else {
			for(int i=0; i<ca.size(); i++) {
				for(int j=0; j<ca.size(); j++) {
					if( ca[i] >= ca[j] )
						continue;
					State there2 = here;
					there2.a[r][c] = ca[i];
					there2.b[r][c] = ca[j];
					there2.finish[r][c] = true;
					there2.count++;
					pq.push(there2);
				}
			}
		}
	}

	return ret;
}

int main(void)
{
	setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		State s;
		for(int i=0; i<6; i++) {
			for(int j=0; j<6; j++) {
				char buf[4];
				scanf("%3s", buf);
				if( buf[1] == '/' ) {
					s.p[i][j] = true;
					s.a[i][j] = (buf[0]=='-')?0:buf[0]-'0';
					s.b[i][j] = (buf[2]=='-')?0:buf[2]-'0';
					if( s.a[i][j] > 0 && s.b[i][j] > 0 ) {
						s.finish[i][j] = true;
						s.count++;
					}
					else
						s.finish[i][j] = false;
				}
				else {
					s.p[i][j] = false;
					s.a[i][j] = (buf[0]=='-')?0:buf[0]-'0';
					s.b[i][j] = 0;
					if( s.a[i][j] > 0 ) {
						s.finish[i][j] = true;
						s.count++;
					}
					else
						s.finish[i][j] = false;
				}
			}
		}
		State ret = search(s);
		printf("#%d\n", test+1);
		for(int i=0; i<6; i++) {
			if( ret.p[i][0] )
				printf("%d/%d", ret.a[i][0], ret.b[i][0]);
			else
				printf("%d", ret.a[i][0]);
			for(int j=1; j<6; j++) {
				if( ret.p[i][j] )
					printf(" %d/%d", ret.a[i][j], ret.b[i][j]);
				else
					printf(" %d", ret.a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}