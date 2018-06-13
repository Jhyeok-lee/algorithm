#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string num;
int memo[10000];

int classify(int a, int b)
{
	string M = num.substr(a, b-a+1);
	if( M == string(M.size(), M[0]) )
		return 1;
	bool progressive = true;
	for(int i=0; i<M.size()-1; i++) {
		if( M[i+1]-M[i] != M[1]-M[0] )
			progressive = false;
	}
	if( progressive && abs(M[1]-M[0])==1 )
		return 2;
	bool alternating = true;
	for(int i=0; i<M.size(); i++) {
		if( M[i] != M[i%2] )
			alternating = false;
	}
	if( alternating )
		return 4;
	if( progressive )
		return 5;
	return 10;
}


int pi(int idx)
{
	if( idx >= num.size() )
		return 0;

	int& ret = memo[idx];
	if( ret != -1 )
		return ret;

	ret = 1234567890;
	for(int i=3; i<=5; i++) {
		if( idx+i <= N.size() )
			ret = min(ret, pi(idx+i) + classify(idx, idx+i-1));
	}
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(memo, -1, sizeof(memo));
		num.clear();
		cin >> num;
		for(int i=0; i<num.size(); i++)
			num[i] -= '0';
	}
}