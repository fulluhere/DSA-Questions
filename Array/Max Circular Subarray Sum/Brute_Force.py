# Maximum Circular Subarray Sum
### 1️⃣ Brute Force
- Generate all subarrays (O(n²)) and calculate sum.
- Take the maximum.

class Solution:
    def maxCircularSum(self, arr):
        n = len(arr)
        max_sum = float('-inf')
        for i in range(n):
            curr_sum = 0
            for j in range(n):
                curr_sum += arr[(i+j) % n]
                max_sum = max(max_sum, curr_sum)
        return max_sum
