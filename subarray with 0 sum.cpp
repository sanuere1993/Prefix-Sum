// Subarray with 0 sum

// Given an array of integers, arr[]. 
// Find if there is a subarray (of size at least one)
// with 0 sum. Return true/false depending upon 
// whether there is a subarray present with 0-sum or not. 

bool subArrayExists(vector<int>& arr) {
	// Your code here
	unordered_map<int,int> arrMap;
	bool ans = false;
	arrMap[0] = 0;
	int presum = 0;
	for(int i = 0 ; i < arr.size() ; i++){
		presum += arr[i];
		
		if (arrMap.find(presum) != arrMap.end()){
			ans = true;
			break;
		}
		else{
			arrMap[presum] = i;
		}
		
	}
	return ans;
	

}
