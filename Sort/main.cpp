#include <iostream>
#include "sort.h"
using std::cout;
using std::endl;

int main()
{
	int a[] = { 5, 4, 3, 2, 2, 4, 10, 11, 6, 20, 78, 63, 45, 20, 69, 12 };
	
	//insert_sort(a, sizeof(a)/sizeof(int));
	merge_insert_sort(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

