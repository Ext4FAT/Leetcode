vector<int> twoSum(vector<int>& nums, int target) {
	int i, j, sum;
	vector<int> res(2);
	sort(nums.begin(), nums.end());
	for (i = 0, j = nums.size() - 1; i < j;){
		sum = nums[i] + nums[j];
		if (sum == target){
			res[0] = i + 1;
			res[1] = j + 1;
			return res;
		}
		else if (sum < target)	i++;
		else j--;
	}
}