### Python
```
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        dp[0] = 0
        dp[1] = 1

        for i in range(2, n + 1):  # Corrected the range
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]
```
### C
```
#include <stdio.h>

int climbStairs(int n) {
    if (n <= 1) {
        return n;
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the number of stairs: ");
    scanf("%d", &n);

    int result = climbStairs(n);

    printf("The number of distinct ways to climb %d stairs is: %d\n", n, result);

    return 0;
}
```
