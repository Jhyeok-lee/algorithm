#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(void)
{
	ofstream out("input4469");
	out << "1\n";
	out << "100000\n";
	for(int i=0; i<100000; i++) {
		out << rand()%10;
		out << "\n";
	}
	for(int i=0; i<99999; i++) {
		out << rand()%10;
		out << "\n";
	}
}