#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class City {
public:
	int l,m,g;
	City(int _l, int _m, int _g)
	{
		l = _l;
		m = _m;
		g = _g;
	}
};

int N, K;
vector<City> city;

bool dicision(int dist)
{
	int ret = 0;
	for(int i=0; i<N; i++) {
		if( dist >= city[i].l - city[i].m )
			ret += (min(dist, city[i].l) -
				(city[i].l-city[i].m))/city[i].g + 1;
	}
	return ret >= K;
}

int optimize()
{
	int lo = 0;
	int hi = 8030001;
	while( lo+1 < hi ) {
		int mid = (lo+hi)/2;
		if( dicision(mid) )
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		city.clear();
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++) {
			int l,m,g;
			scanf("%d %d %d", &l, &m, &g);
			City c(l,m,g);
			city.push_back(c);
		}
		int ret = 0;
		ret = optimize();
		printf("%d\n", ret);
	}
}