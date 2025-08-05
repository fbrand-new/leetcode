#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // nums size is always odd since its n*2 + 1

        if (nums.size() == 1)
            return nums[0];
        // If branch size is odd, and sibling on the left side, the odd one lives on the right branch
        // and viceversa is true
        const int n = nums.size();
        int left = 0;
        int right = n;
        
        while (left < right) //different than both sides
        {
            int mid = (left + right)/2;

            if (mid == 0)
                break;
            else if (mid == n)
                break;

            if (nums[mid] == nums[mid-1] && mid%2 == 1 || nums[mid] == nums[mid+1] && mid%2 == 0)
            {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        
        return nums[(left+right)/2];
    }
};

int main(){
    std::vector<int> nums = {1,1,2,3,3,4,4,8,8};
    nums = {3,3,7,7,10,11,11};
    nums = {1,2,2,3,3};
    auto sol = Solution();
    int res = sol.singleNonDuplicate(nums);
    cout << res << "\n";
}