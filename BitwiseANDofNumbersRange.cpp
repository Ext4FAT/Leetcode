int rangeBitwiseAnd(int m, int n) {
	int bit;
	//��ǰ׺
	for (bit = 0; m!=n; bit++) {
		m >>= 1;
		n >>= 1;
	}
	//�������ǰ׺
	return m << bit;
}