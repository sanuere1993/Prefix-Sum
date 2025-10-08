// 2559. Count Vowel Strings in Ranges


// You are given a 0-indexed array of strings words and a 2D array of integers queries.
// Each query queries[i] = [li, ri] asks us to find the number of strings present at the 
// indices ranging from li to ri (both inclusive) of words that start and end with a vowel.
// Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

// Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

TC:O(m+n)
SC:O(n)

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
	int vowelstr = 0 , count;
	unordered_set<char> st;
	int m = words.size() , p = queries.size();
	vector<int> prearr (m);
	vector<int> ans (p);
	st.insert('a');
	st.insert('e');
	st.insert('i');
	st.insert('o');
	st.insert('u');
	for (int i = 0 ; i < words.size() ; i++){
		int n = words[i].size();
		if (st.find(words[i][0]) != st.end() && st.find(words[i][n-1]) != st.end()){
			count = 1;
		}
		else{
			count = 0;
		}
		vowelstr += count;
		prearr[i] = vowelstr;
	}

	for (int i = 0 ; i < queries.size() ; i++){
		if (queries[i][0]-1 < 0){
			ans[i] = prearr[queries[i][1]];
		}
		else{
			ans[i] = prearr[queries[i][1]] - prearr[queries[i][0]-1];
		}
		
	}
	return ans;
}