#ifndef _COMMON_H_
#define _COMMON_H_

template <typename T>
inline void exchange(T &x, T &y)
{
	T t = x;
	x = y;
	y = t;
}

#endif // _COMMON_H_
