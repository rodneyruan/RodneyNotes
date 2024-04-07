## Table of Contents
- [Move Zeros](#move-zeros)
- [Remove Duplicates From Sorted Array](#remove-duplicates-from-sorted-array)
- [Climbing Stairs](#climbing-stairs)
- [Palindrome Number](#palindrome-number)
- [Decoded String](#decoded-string)
- [Lemonade Change](#lemonade-change)
- [Unique Paths](#unique-paths)
# Move Zeros
## Problem Description
```
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
```
## Code
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        i = 0
        j = 0
        count = 0
        for i in range(n):
            if( i!= j):
                nums[j]=nums[i]
            if(nums[i] == 0):
                count+=1
            else:
                j+=1
        for i in range(n-count,n):
            nums[i] = 0
```
# Remove Duplicates From Sorted Array
## Problem Description
```
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
The remaining elements of nums are not important as well as the size of nums.
Return k.
```
## Code
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        Removes duplicates from the given sorted integer array nums in-place,
        maintaining the relative order of elements. Returns the number of unique elements.

        Args:
        nums: List of integers sorted in non-decreasing order

        Returns:
        int: Number of unique elements in nums
        """
        n = len(nums)
        k = 0  # Pointer to track the position to store the next unique element
        
        # Iterate through the array
        for i in range(1, n):
            # If the current element is not equal to the previous unique element,
            # update nums at position k+1 with the current element
            if nums[i] != nums[k]:
                k += 1
                nums[k] = nums[i]
        
        # Return the number of unique elements (k+1 as k is 0-indexed)
        return k + 1
```
# Climbing Stairs
## Problem Description
```
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
```
## Code
Python
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
C
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
# Palindrome Number
```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        s=str(x)
        left=0
        right=len(s)-1
        while(left<right):
            if(s[left]!=s[right]):
                return False
            left+=1
            right-=1
        return True
```
更高效的版本
```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        temp = x
        reversed = 0
        while(temp != 0):
            digit=temp % 10
            temp=temp//10
            reversed = reversed*10+digit
        return (reversed == x)
```

# decoded string
## 
```
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```
## code
```
class Solution:
    def decodeString(self, s: str) -> str:
        stack =[] 
        stack_num = []
        n=len(s)
        tmp=""
        num=""
        for i in range (n):
            if (s[i] >= '0' and s[i] <='9'):
                 num = num + s[i]
            elif (s[i] >= 'a' and s[i] <='z'):
                 tmp = tmp + s[i]
            if(s[i] == '['):
                stack_num.append( int(num))
                stack.append(tmp)
                #print("number pushed to stack is %d, string is %s"  %(int(num),tmp))
                num = ""
                tmp = ""
            elif (s[i] == ']'):
                k= stack_num.pop()
                tmp *= k
                tmp  = stack.pop() +tmp
                #print("j is %s, k is %d" % (tmp,k))
        return tmp 
```

# Lemonade Change
## Problem Description
```
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.
```
## Code
```
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        n5 = 0
        n10 = 0
        for i in bills:
            if i == 5:
                n5 += 1
            elif i == 10:
                if( n5 <= 0):
                    return False
                else:
                    n5 -= 1
                    n10 += 1
            elif i == 20:
                if n10>=1 and n5 >=1:
                    n10 -= 1
                    n5 -= 1
                elif n5 >= 3:
                    n5 -=3
                else:
                    return False
        return True
```
#  Unique Paths
## Problem Description
```
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
```
## Code
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0]*n for _ in range(m)]
        for i in range (m):
            dp [i][0] = 1
        for i in range (n):
            dp[0][i] = 1
        
        for i in range (1,m):
            for j in range (1,n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[m-1][n-1]
```
# Blog
https://blog.algomooc.com/LeetCode
