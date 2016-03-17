#ifndef _SORT_H_
#define _SORT_H_

#include "common.h"


/****** Selection Sort Algorithm ******/

template <typename T>
void select_sort(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return;

	for (int i = 0; i < n - 1; ++i) {
		int min_id = i;
		for (int j = i + 1; j < n; ++j)
			if (d[j] < d[min_id]) min_id = j;
		exchange(d[i], d[min_id]);
	}
}


/****** Bubble Sort Algorithm ******/

template <typename T>
void bubble_sort(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return;

	for (int i = 0; i < n - 1; ++i)
		for (int j = n - 1; j > i; --j)
			if (d[j] < d[j - 1]) exchange(d[j], d[j - 1]);
}


/****** Insertion Sort Algorithm ******/

template <typename T>
void insert_sort(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return;

	for (int i = 1; i < n; ++i) {
		T key = d[i];
		int j;
		for (j = i - 1; j >= 0 && key < d[j]; --j) {
			d[j+1] = d[j];
		}
		d[j+1] = key;
	}
}

/****** Merge Sort Algorithm ******/

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
		merge_sort(d, t, q+1, r);
		merge(d, t, p, q, r);
	}
}

template <typename T>
void merge_sort(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return;

	T *t = new T[n];
	merge_sort(d, t, 0, n-1);
	delete[] t;
}


/****** Merge-Insert Sort Algorithm ******/

template <typename T>
void merge_insert_sort(T d[], T t[], int p, int r)
{
	static const int critical_len = 10;
	int n = r - p + 1;

	if (n > critical_len) {
		int q = (p + r) / 2;
		merge_sort(d, t, p, q);
		merge_sort(d, t, q + 1, r);
		merge(d, t, p, q, r);
	}
	else {
		insert_sort(d + p, n);
	}
}

template <typename T>
void merge_insert_sort(T d[], int n)
{
	if (n <= 1 || d == NULL)
		return;

	T *t = new T[n];
	merge_insert_sort(d, t, 0, n-1);
	delete[] t;
}

#endif // _SORT_H_
