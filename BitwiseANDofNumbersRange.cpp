int rangeBitwiseAnd(int m, int n) {
	int bit;
	//找前缀
	for (bit = 0; m!=n; bit++) {
		m >>= 1;
		n >>= 1;
	}
	//返回最大前缀
	return m << bit;
}