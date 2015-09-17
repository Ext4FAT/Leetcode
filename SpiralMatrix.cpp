vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (!matrix.size() || !matrix[0].size()) return {};
	int cnt, h, w, i, j;
	vector<int> res;
	if (!(h = matrix.size() - 1))	return matrix[0];
	if (!(w = matrix[0].size() - 1)) {
		for (i = 0; i < matrix.size(); i++) 
			res.push_back(matrix[i][0]);
		return res;
	}
	for (i = j = cnt = 0; h >= 0 && w >= 0; i++, j++, h -= 2, w -= 2){
		if (!h && !w)   res.push_back(matrix[i][j]);
		for (cnt = w; cnt; cnt--) res.push_back(matrix[i][j++]);
		for (cnt = h; cnt; cnt--) res.push_back(matrix[i++][j]);
		for (cnt = w; cnt; cnt--) res.push_back(matrix[i][j--]);
		for (cnt = h; cnt; cnt--) res.push_back(matrix[i--][j]);
	}
	if (matrix.size() != matrix[0].size() && (matrix.size()*matrix[0].size())&1 )  
		res.pop_back();
	return res;
}