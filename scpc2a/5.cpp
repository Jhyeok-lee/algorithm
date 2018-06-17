#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Rec {
public:
	int xlo, ylo, xhi, yhi;
	Rec(int _xlo, int _ylo, int _xhi, int _yhi)
	{
		xlo = _xlo;
		ylo = _ylo;
		xhi = _xhi;
		yhi = _yhi;
	}
};

int N,M,K;
vector<Rec> R;
vector<int> height;

bool cmp(Rec& l, Rec& r)
{
	long long lx = l.xhi-l.xlo;
	long long rx = r.xhi-r.xlo;
	long long ly = l.yhi-l.ylo;
	long long ry = r.yhi-r.ylo;
	return lx*ly < rx*ry;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		R.clear();
		scanf("%d %d %d", &N, &M, &K);
		//R.push_back(Rec(0,0,N,M));
		for(int i=0; i<K; i++) {
			int a,b,c,d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			R.push_back(Rec(a,b,c,d));
		}
		sort(R.begin(), R.end(), cmp);
		height = vector<int>(K, 1);
		for(int i=0; i<K; i++) {
			for(int j=i-1; j>=0; j--) {
				if( R[i].xlo <= R[j].xlo && R[j].xhi <= R[i].xhi &&
					R[i].ylo <= R[j].ylo && R[j].yhi <= R[i].yhi )
					height[i] = max(height[i], height[j]+1);
			}
		}
		int ret = *max_element(height.begin(), height.end());
		printf("Case #%d\n%d\n", test+1, ret);
	}
}