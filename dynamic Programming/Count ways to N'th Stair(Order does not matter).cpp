// There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
// Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

// Example 1:

// Input:
// N = 4
// Output: 3
// Explanation: You can reach 4th stair in
// 3 ways.
// 3 possible ways are:
// 1, 1, 1, 1
// 1, 1, 2
// 2, 2
// Example 2:

// Input:
// N = 5
// Output: 3
// Explanation:
// You may reach the 5th stair in 3 ways.
// The 3 possible ways are:
// 1, 1, 1, 1, 1
// 1, 1, 1, 2
// 1, 2, 2
// Your Task:
// Your task is to complete the function countWays() which takes single argument(N) and returns the answer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 106

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n)
    {
        long long dp[n + 1];

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
        }
        return dp[n];
    }
};