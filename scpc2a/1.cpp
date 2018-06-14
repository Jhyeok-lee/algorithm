#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
int X[20];
int Y[20];
int S[20];

double cal(double x, double y)
{
	vector<double> u;
	for(int i=0; i<N; i++)
		u.push_back(fabs(x-(double)X[i]) + fabs(y-(double)Y[i]));
	sort(u.begin(), u.end());
	for(int i=K-1; i>=0; i--)
		u[K-1-i] += (double)S[i];
	sort(u.begin(), u.end());
	return u[N-1];
}

double search(double x, double ylo, double yhi)
{
	for(int j=0; j<30; j++) {
		double ya = (2*ylo+yhi)/3.0;
		double yb = (ylo+2*yhi)/3.0;
		if( cal(x,ya) > cal(x,yb) )
			ylo = ya;
		else
			yhi = yb;
	}
	return cal(x, yhi);
}

int main(void)
{
	setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++)
			scanf("%d %d", &X[i], &Y[i]);
		for(int i=0; i<K; i++)
			scanf("%d", &S[i]);
		sort(S, S+K);
		double xlo = 1000001;
		double ylo = 1000001;
		double xhi = 0;
		double yhi = 0;
		for(int i=0; i<N; i++) {
			xlo = min(xlo, (double)X[i]);
			ylo = min(ylo, (double)Y[i]);
			xhi = max(xhi, (double)X[i]);
			yhi = max(yhi, (double)Y[i]);
		}
		double ret = 1e18;
		for(double x=xlo; x<=xhi; x++)
			ret = min(ret, search(x,ylo,yhi));
		printf("Case #%d\n%.1lf\n", test+1, ret);
	}
}