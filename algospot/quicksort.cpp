#include <iostream>
#include <cstdlib>

using namespace std;

void sort(int arr[], int lo, int hi)
{
	int i = lo;
	int j = hi;
	int pivot = arr[(i+j)/2];

	while( i <= j ) {
		while( arr[i] < pivot )
			i++;
		while( arr[j] > pivot )
			j--;
		if( i <= j ) {
			swap( arr[i], arr[j] );
			i++;
			j--;
		}
	}

	if( j > lo )
		sort(arr, lo, j);
	if( i < hi )
		sort(arr, i, hi);
}

int main(void)
{
	int arr[100] = {0,};
	for(int i=0; i<100; i++)
		arr[i] = rand()%100;
	for(int i=0; i<100; i++)
		printf("%d ", arr[i]);
	printf("\n");
	sort(arr, 0, 99);
	for(int i=0; i<100; i++)
		printf("%d ", arr[i]);
	printf("\n");
}