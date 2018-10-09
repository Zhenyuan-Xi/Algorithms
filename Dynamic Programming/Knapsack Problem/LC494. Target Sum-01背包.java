/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int n = nums.length;
        int sum = 0;
        for (int num : nums) sum += num;
        if (S > sum || S < -sum) return 0;
      // sum的取值范围为[-sum,sum],即sum的位置为0点
      // F(i, j): 由前i个元素求和得到j的方式的数量
      // F(i, j) = F(i-1, j+nums[i-1]) + F(i-1, j-nums[i-1]), 即加号和减号的方式之和
        int[][] dp = new int[n + 1][2 * sum + 1];
        dp[0][sum] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2 * sum; j++) {
                if (j + nums[i - 1] <= 2 * sum)
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][sum + S];
    }
}
