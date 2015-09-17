//  0   1    2      3       4
//	+/- d   E/e   space  can_accept
int trans[3][5] = {
	{ 1, 2, -1, 0 },
	{ -1, 2, -1, -1 },
	{ -1, 2, 3, 5 }
};

int myAtoi(string str) {
	char pos[128], c;
	int state = 0;
	long res = 0, sign = 1, pow = 0;
	memset(pos, -1, 128);
	pos['e'] = pos['E'] = 2;
	pos['+'] = pos['-'] = 0;
	pos[' '] = 3;
	memset(pos + 48, 1, 10);
	for (int i = 0; (c = str[i]) && pos[c] >= 0; i++){
			state = trans[state][pos[c]];
			switch (state){
				case 0: break;
				case 1: sign = c == '-'?  -1 : 1;   break;
				case 2: res = 10 * res + c - '0';
						if(res>=2147483648L)
						return sign > 0? 2147483647: -2147483648;
						break;
				default:return res*sign;
			}
	}
	return res*sign;