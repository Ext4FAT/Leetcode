void reverseWords(string &s) {
	stringstream ss;
	string sub;
	int st, en;
	reverse(s.begin(), s.end());
	for (st = en = 0; s[st]; st = en){
		for (en = st; s[en] == ' '; en++);
		for (st = en; s[en] && s[en] != ' '; en++);
		sub = s.substr(st, en - st);
		reverse(sub.begin(), sub.end());
		s[en]? ss << sub << " " : ss << sub;
	}
	s = ss.str();
	if(s[s.size() - 1]==' ')  s.pop_back();
}