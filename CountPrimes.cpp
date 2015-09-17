//∞£ œ…∏—°∑®
int countPrimes(int n) {
	int i, j, res;
	vector<bool> isPrimes(n+1, true);
	for (i = 2; i <= n; i++)
		if(isPrimes[i])
			for(j = 2; j * i <= n; j++)
				isPrimes[j*i] = false;
	for (res = 0, i = 2; i < n; i++)
		if(isPrimes[i])
			res++;
	return res;
}