class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        ans = 0
        a = 0

        for i in nums:

            if i == 0:
                ans = max(a, ans)
                a = 0
            else:
                a += 1

        ans = max(a, ans)

        return ans

        