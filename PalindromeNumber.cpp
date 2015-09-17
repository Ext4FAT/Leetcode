bool isPalindrome(int x) {
	if (x < 0) return false;
	if (!x) return true;
	int res, m;
	for (m = x, res = 0; x; x /= 10)
		res = 10 * res + x % 10;
	return res == m;
}