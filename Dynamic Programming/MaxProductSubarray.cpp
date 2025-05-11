/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

/*
Brute: Compute all products of all possible subarrays 
TC: O(N^3) 


Observations:
1) if the array has only positive numbers -> we can confidently state that the entire array is our answer

2) if the array consists of an even number of negative numbers, again the entire array is our required subarray

Now, when there are an odd number of negative numbers in the array, we need to think of which one to remove such that the product of elements of the subarrays on either side of the number is maximized

- one method which we can use is to compute left and right products (prefix and suffix) for each of the negative number and decide which of them is maximum

- we should NEVER consider 0s in our answer; as it will always result in a 0 and we want to obtain the maximum possible product

FINAL THOUGHTS:

- initialize a variable pre = 1, and suff = 1; these variables store the products of the prefix and suffix elements of the array
- if either of them become zero : reset them to 1
- at each index, we'll keep track of the maximum product obtained so far

*/

int maxProductSubarray(vector<int> &nums){
    int pre = 1;
    int suff = 1;
    int ans = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(suff, pre));
    }
    return ans;
}