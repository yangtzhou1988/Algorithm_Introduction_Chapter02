#include <iostream>
#include "Inversion.h"

using std::cout;
using std::endl;

int main()
{
	int a[] = {2, 3, 8, 6, 1};
	int b[] = {0, 1};

	cout << InversionNum(b, sizeof(b)/sizeof(int)) << endl;

	return 0;
}
