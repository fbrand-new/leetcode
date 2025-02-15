#include <vector>
#include <iostream>

using namespace std;

// Requirements specifies to solve in O(n) without using the division op

// Compute all prefices and all suffices O(2n)

// Multiply prefix[i] * suffix[n-i]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        size_t n = nums.size();

        //Compute all the prefices. prefix[0] = 1
        vector<int> prefices(n,1);
        for(size_t k=1; k<n; ++k){
            prefices[k] = prefices[k-1] * nums[k-1];
        }


        //Compute all the suffices. suffices[n] = 1
        vector<int> suffices(n,1);
        for(int k=n-2; k>=0; --k){
            suffices[k] = suffices[k+1] * nums[k+1];
        }

        //The result vector is prefix[i]*suffix[i]
        vector<int> result(n);
        for(size_t k=0; k<n; ++k){
            result[k] = prefices[k]*suffices[k];
        }

        return result;

    }
};

int main()
{
    vector<int> nums{1,2,3,4};

    Solution sol;

    auto res = sol.productExceptSelf(nums);

    for(auto r: res){
        cout << r << ",";
    }
}