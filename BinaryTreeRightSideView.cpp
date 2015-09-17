vector<int> rightSideView(TreeNode* root) {
	if(!root)   return {};
	queue<pair<TreeNode*,int>>    q;
	vector<int> res;
	TreeNode* tmp;
	int level;
	for (q.push({root, 0}); !q.empty(); ){
		tmp = q.front().first;
		level = q.front().second;
		q.pop();
		if(q.empty() || level != q.front().second)
			res.push_back(tmp->val);
		if(tmp->left)
			q.push({tmp->left, level+1});
		if(tmp->right)
			q.push({tmp->right, level+1});
	}
	return res;
}