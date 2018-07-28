class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int len = nums.size();

        for (int num : nums) {
            map[num]++;

            if (map.find(num)->second > len / 2) {
                return num;
            }
        }

        return -1;
    }
};
static const auto ______ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//Boyer-Moore Voting Algorithm
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate