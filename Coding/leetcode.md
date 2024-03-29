## Table of Contents
- [Move Zeros](#move-zeros)
- [Remove Duplicates From Sorted Array](#remove-duplicates-from-sorted-array)
- [Climbing Stairs](#climbing-stairs)
- [Palindrome Number](#palindrome-number)
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
# Blog
https://blog.algomooc.com/LeetCode
