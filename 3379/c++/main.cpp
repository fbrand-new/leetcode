#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
    
        std::vector<int> result;

        const std::size_t n = nums.size();
        
        for (std::size_t i=0; i<n; ++i){
            if (nums[i] > 0){
                int k = (i + nums[i])%n;
                result.push_back(nums[k]);
            }
                
            else if (nums[i] < 0)
            {
                int k = (int(i) + nums[i])%int(n);
                // std::cout << "i" << i << "k" << k << "\n";
                if (k >= 0)
                    result.push_back(nums[k]);
                else
                {
                    // std::cerr << n-k;
                    result.push_back(nums[n+k]);
                }

            }
            else {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};
