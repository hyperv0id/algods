class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        soll = collections.Counter(nums)
        return [x[0] for x in list(soll.most_common(k))]
    