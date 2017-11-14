#ifdef __cplusplus
extern "C" {
#endif
#include <cstdio>

double min(double a, double b) {
	/*
	double _min = x[0];
	int posi = 0;
	for (int i = 1;i < length;++ i)
		if (_min > x[i])
		{
			_min = x[i];
			posi = i;
		}
	return posi;
	*/
	return a > b ? b : a;
}
#ifdef __cplusplus
}
#endif
