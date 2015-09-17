//	+/- d . e/E space can_accept
int trans[11][6] = {
	{ 1, 2, 8, -1, 0, 0 },
	{ -1, 2, 8, -1, -1, 0 },
	{ -1, 2, 3, 5, 10, 1 },
	{ -1, 4, -1, 5, 10, 1 },
	{ -1, 4, -1, 5, 10, 1 },
	{ 6, 7, -1, -1, -1, 0 },
	{ -1, 7, -1, -1, 10, 0 },
	{ -1, 7, -1, -1, 10, 1 },
	{ -1, 9, -1, -1, -1, 0 },
	{ -1, 9, -1, 5, 10, 1 },
	{ -1, -1, -1, -1, 10 ,1}
}; 
bool isNumber(string s) {
	// Write your code here
	char pos[128], c;
	int state = 0;
	memset(pos, -1, 128);
	pos['e'] = pos['E'] = 3;
	pos['+'] = pos['-'] = 0;
	pos['.'] = 2;
	pos[' '] = 4;
	memset(pos + 48, 1, 10);
	for(int i = 0; c = s[i]; i++)
		if (pos[c] >= 0){
			state = trans[state][pos[c]];
			if(state < 0)  return false;
		}	
		else return false;
	if(trans[state][5]) return true;
	return false;
}