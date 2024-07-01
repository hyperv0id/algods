# https://leetcode.cn/problems/sliding-window-maximum/submissions/419847891/
from typing import *


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from collections import deque
        que = deque()
        ans =[]
        for i, n in enumerate(nums):
            
            # 前面的都比我小
            while que and nums[que[-1]] <= n:
                que.pop()   
             
            que.append(i)

            # 溢出
            if que[0] + k == i:
                que.popleft()
            
            if i >= k-1:
                ans.append(nums[que[0]])
        
        return ans