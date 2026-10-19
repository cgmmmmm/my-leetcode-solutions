class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Time Complexity: O(nlogn + n)
        #   - Sorting the list is O(nlogn)
        #   - Traverse the list to find target is O(n)
        # Brute-force Approach
        nums = sorted(nums)

        res = []

        for i in range(len(nums)):
            if nums[i] == target:
                res.append(i)

        return res
        
