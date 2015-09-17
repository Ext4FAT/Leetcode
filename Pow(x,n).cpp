double powerful(double x,int n){
	if(n == 1)    return x;
	if(n == 2)    return x * x;
	double div = powerful(x, n / 2);
	if(n % 2) return x * div * div;
	return div * div;
}

double myPow(double x, int n) {
	if(!n || x == 1.0)  return 1.0;
	if(x == -1.0) return n & 1 ? -1.0: 1.0;
	if(n < 0) { n = -n; x = 1/x ;}
	powerful(x,n);
}