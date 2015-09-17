#define EXCHANGE(X, Y)  \   
		TreeNode* tmp = X;         \
		X = Y;         \
		Y = tmp;

void exchange(TreeNode* root){
	if(!root)   return;         
	exchange(root->left); 
	exchange(root->right);
	EXCHANGE(root->left, root->right);
}

TreeNode* invertTree(TreeNode* root) {
	exchange(root);
	return root;
}