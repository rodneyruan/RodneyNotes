### fibonacci
```
def fibonacci(n):
    # Create a memoization table to store computed results
    memo = {}

    # Base cases
    if n <= 1:
        return n

    # Check if the result is already in the memo table
    if n in memo:
        return memo[n]

    # Recursive calls with memoization
    result = fibonacci(n - 1) + fibonacci(n - 2)

    # Store the result in the memo table
    memo[n] = result

    return result

# Example usage
n = 10
result = fibonacci(n)
print(f"The {n}-th Fibonacci number is: {result}")

```
```
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
​
        dp = [0 for _ in range(n + 1)]
        dp[0] = 0
        dp[1] = 1
​
        for i in range(2, n + 1):
            dp[i] = dp[i - 2] + dp[i - 1]
​
        return dp[n]
```
