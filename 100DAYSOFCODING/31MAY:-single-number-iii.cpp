class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const auto x_xor_y =
            accumulate(nums.cbegin(), nums.cend(), 0u, bit_xor<int>());
        const auto bit = x_xor_y & -x_xor_y;
        vector<int> result(2, 0);
        for (const auto& i : nums) {
            result[static_cast<bool>(i & bit)] ^= i;
        }
        return result;
    }
};
