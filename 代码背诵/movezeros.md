### Move Zeros
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

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
