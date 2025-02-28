from typing import List

class Solution:

    # Find zero and bubble it until the en

    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Fast start
        try:
            start = nums.index(0)
        except:
            return
        
        for i in range(start,len(nums)):
            if nums[i] != 0:
                nums[start], nums[i] = nums[i], nums[start]
                start += 1

if __name__ == "__main__":
    nums = [0,1,0,3,12]
    # nums = [1]
    sol = Solution()
    sol.moveZeroes(nums)
    print(nums)