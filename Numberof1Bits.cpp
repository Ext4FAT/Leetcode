int hammingWeight(uint32_t n) {
	int cnt;
	for (cnt = 0; n; cnt++)
		n &= n-1;
	return cnt;
}