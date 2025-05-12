/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

/*
Since we need to print the length of the longest possible subsequence in an increasing order, using greedy approach would fail because it is not taking into account various cases.

This requires a recursive approach.
We need to take into account the previous index as well so that we can compare our current index with it.

So a general pseudo function comes out to be as follows:
Base case: if the index comes out to be equal to n, which is the size of the array, it means we have traversed the entire array - so we return 0.

f(index, prev_index){
    //base case
    if(index == n)
        return 0;
    
    int notTake = 0 + f(index + 1, prev_index);
    int take = 0;
    if(prev_index == 0 || arr[index] > arr[prev_index]){
        take = 1 + f(index + 1, index);
    }
    return max(take, notTake);
}
*/

// FINAL MEMOIZED CODE

int getAns(int ind, int prev_ind, vector<int> &arr, int n, vector<vector<int>> &dp){
    //base case
    if(ind == n)
        return 0;
    
    if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

    int notTake = getAns(ind + 1, prev_ind, arr, n, dp);
    int take = 0;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind])
        take = 1 + getAns(ind + 1, ind, arr, n, dp);

    return dp[ind][prev_ind + 1] = max(take, notTake);
}

int longestIncreasingSubsequence(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return getAns(0, -1, arr, n, dp);
}