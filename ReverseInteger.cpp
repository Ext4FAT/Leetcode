int reverse(int x) {
	long sign, res, tmp;
	for (res = 0, sign = x < 0? -1: 1, tmp = x * sign; tmp; tmp /= 10)
		res = 10 * res + tmp % 10;
	if (res > 0x7fffffff)   return 0;
	return sign > 0? res: -res;
}