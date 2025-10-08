// 2587. Rearrange Array to Maximize Prefix Score

// You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).

// Let prefix be the array containing the prefix sums of nums after rearranging it. In other words, 
// prefix[i] is the sum of the elements from 0 to i in nums after rearranging it. 
// The score of nums is the number of positive integers in the array prefix.

// Return the maximum score you can achieve.

Example 1:

Input: nums = [2,-1,0,1,-3,3,-3]
Output: 6
Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
prefix = [2,5,6,5,2,2,-1], so the score is 6.
It can be shown that 6 is the maximum score we can obtain.

TC: O(nlogn)
SC: O(1)



int maxScore(vector<int>& nums) {
	sort(nums.begin() , nums.end() , greater<int>());
	long long int presum = 0 ;
	int count = 0;
	for (int i = 0 ; i < nums.size() ; i++){
		presum += nums[i];
		if (presum > 0){
			count++;
		}
	}
	return count;
}