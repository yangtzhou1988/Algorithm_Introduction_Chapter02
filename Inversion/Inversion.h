#ifndef _INVERSION_H_
#define _INVERSION_H_

#define _PRINT_INVERSION_ENABLE_

#ifdef _PRINT_INVERSION_ENABLE_
#include <iostream>
using std::cout;
using std::endl;
#endif

template <typename T>
void merge(T d[], T t[], int p, int q, int r)
{
	// copy elements to temporary array
	for (int i = p; i <= r; ++i)
		t[i] = d[i];

	int i = p;		// left side index
	int j = q + 1;	// right side index
	int k = p;		// original array index

	while (i <= q && j <= r) {
		if (t[j] < t[i]) d[k++] = t[j++];	// right min < left min
		else d[k++] = t[i++];				// left min <= right min
	}

	while (i <= q) d[k++] = t[i++];		// left side remain elements
	while (j <= r) d[k++] = t[j++];		// right side remain elements
}

template <typename T>
int CrossInversionNum(T d[], int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int num = 0;

	while (i <= q && j <= r) {
		if (d[i] > d[j]) {
			num += (q-i+1);
#ifdef _PRINT_INVERSION_ENABLE_
			for (int k = i; k <= q; ++k)
				cout << "(" << d[k] << ", " << d[j] << ")" << endl;
#endif
			++j;
		}
		else
			++i;
	}

	return num;
}

template <typename T>
int InversionNum(T d[], T t[], int p, int r)
{
	int num = 0;

	if (p < r) {
		int q = (p + r) / 2;
		num += InversionNum(d, t, p, q);
		num += InversionNum(d, t, q+1, r);
		num += CrossInversionNum(d, p, q, r);
		merge(d, t, p, q, r);
	}

	return num;
}

template <typename T>
int InversionNum(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return 0;

	T *t1 = new T[n];
	T *t2 = new T[n];

	for (int i = 0; i < n; ++i)
		t1[i] = d[i];

	int num = InversionNum(t1, t2, 0, n - 1);

	delete[] t1;
	delete[] t2;

	return num;
}

#endif // _INVERSION_H_
