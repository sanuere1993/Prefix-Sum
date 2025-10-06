

// You are given a 0-indexed integer array nums. 
// There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. 
// If there is no such j, set arr[i] to be 0.

// Return the array arr.

T(C) : O(N)
S(C) : O(N)


Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation: 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
 

vector<long long> distance(vector<int>& nums) {
	unordered_map<int, long long> mp;
	unordered_map<int, vector<int>> indices;
	long long n = nums.size();
	vector<long long> output (n); 
	for (int i = 0; i < nums.size() ; i++){
		if(mp.find(nums[i]) != mp.end()){
			mp[nums[i]] = mp[nums[i]] + i;
		}
		else{
			mp[nums[i]] = i;
		}
		indices[nums[i]].push_back(i);
	}
	long long ans , sum;
	for(auto &it : indices){
		int n = it.second.size();
		sum = 0;
		for (int i = 0 ; i < it.second.size() ; i++){
			sum +=(it.second)[i];
			long long before = i - 0;
			long long after = n - i;
		
			ans = mp[it.first] - (it.second)[i]*after +  (it.second)[i]*before - 2*((sum - (it.second)[i]));
			output[(it.second)[i]] = ans;
		}
	}
    return output;
        
}