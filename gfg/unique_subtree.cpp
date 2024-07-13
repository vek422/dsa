//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  // Function to return the total number of possible unique BST.
  int numTrees(int N) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(N + 1, 0);
    dp[0] = dp[1] = 1;

    for (int n = 2; n <= N; n++) {
      for (int i = 1; i <= n; i++) {
        dp[n] = (dp[n] + (dp[i - 1] * dp[n - i]) % MOD) % MOD;
      }
    }

    return dp[N];
  }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main() {

  // taking total testcases
  int t;
  cin >> t;
  while (t--) {

    // taking total number of elements
    int n;
    cin >> n;
    Solution ob;
    // calling function numTrees()
    cout << ob.numTrees(n) << "\n";
  }
}
// } Driver Code Ends
