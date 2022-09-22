// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.

// Example 1

// Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.
// Example 2

// Input:
// X = efgh, Y = jghi
// Output: 6
// Explanation: Shortest Common Supersequence
// would be ejfghi which is of length 6 and
// has both the strings as its subsequences.
// Your Task:
// Complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

// Expected Time Complexity: O(Length(X) * Length(Y)).
// Expected Auxiliary Space: O(Length(X) * Length(Y)).

// Constraints:
// 1<= |X|, |Y| <= 100

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int lcs(string x, string y, int m, int n)
    {
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (x[i - 1] == y[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        int sizeLcs = lcs(x, y, m, n);
        return (m + n - sizeLcs);
    }
};