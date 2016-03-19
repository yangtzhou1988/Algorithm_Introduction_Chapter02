#include <iostream>

using std::cout;
using std::endl;

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
void merge_sort(T d[], T t[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(d, t, p, q);
		merge_sort(d, t, q + 1, r);
		merge(d, t, p, q, r);
	}
}

template <typename T>
void merge_sort(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return;

	T *t = new T[n];
	merge_sort(d, t, 0, n - 1);
	delete[] t;
}

void FindTwoDigitsSum(int d[], int n, int x)
{
	if (n < 2 || d == NULL)
		return;

	int *t = new int[n];
	for (int i = 0; i < n; ++i)
		t[i] = d[i];

	merge_sort(t, n);
	
	int i = 0;
	int j = n - 1;

	while (i < j) {
		if (t[i] + t[j] < x) ++i;
		else if (t[i] + t[j] > x) --j;
		else {
			cout << t[i] << "\t" << t[j] << endl;
			break;
		}
	}

	delete[] t;
}

int main()
{
	int a[] = {3, 9, 11, 48, 60, 75, 28, 31, 20, 74};

	FindTwoDigitsSum(a, sizeof(a)/sizeof(int), 149);

	return 0;
}
