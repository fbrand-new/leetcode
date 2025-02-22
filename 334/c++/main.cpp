#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

//I thought this was the case but it is not true

    // Main intuition: you can do O(n) by noticing that
    // you can keep track of the minimum and of the second minimum
    // Any valid sequence will have the minimum as the first number,
    // since this is the best case scenario (i.e. if you were not able
    // to find a good sequence until now, then an eventual valid sequence
    // from there on will for sure include the minimum):w

// We instead need to keep track of the smallest current valid **couple** of numbers
// and keep on looking for the last element of the triplet, updating the second term of the couple
// if something smaller comes in, or updating the couple if the top element is smaller 



class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int min = nums[0];
        size_t min_idx = 0;
        int second_min = -1;
        size_t second_min_idx = -1;

        size_t i=1;
        //Initialize
        for(;i<nums.size();++i)
        {
            if(nums[i] <= min)
            {
                min = nums[i];
                min_idx = i;
                continue;
            }
            else {
                second_min = nums[i];
                second_min_idx = i;
                break;
            }
        }

        if(second_min_idx==-1 || second_min_idx==nums.size())
        {
            return false;
        }

        // Now min and second min are always different
        int possible_new_min = 0;
        size_t possible_new_min_idx = -1;

        while(i<nums.size())
        {
            // If nums
            if (nums[i] > second_min)
            {
                return true;
            }
            else 
            {
                if(nums[i] > min)
                {
                    // We may update the couple if there is a possible new min
                    if(possible_new_min_idx != -1)
                    {
                        min = possible_new_min;
                        min_idx = possible_new_min_idx;

                        // Reset possible new min idx
                        possible_new_min_idx = -1;
                    }

                    second_min = nums[i];
                    second_min_idx = i;
                    ++i;
                    continue;
                }
                else 
                {
                    if(possible_new_min_idx != -1 && nums[i] > possible_new_min)
                    {
                        min = possible_new_min;
                        min_idx = possible_new_min_idx;
                        second_min = nums[i];
                        second_min_idx = i;
                        possible_new_min_idx = -1;
                        i++;
                        continue;
                    }

                    possible_new_min = nums[i];
                    possible_new_min_idx = i;
                    ++i;
                    continue;
                }
            }

            i++;
        }

        return false;

    }
};

int main()
{
    //vector<int> nums{1,2,3,4,5};
    // vector<int> nums{5,1,6};
    // vector<int> nums{20,100,10,12,5,13};
    vector<int> nums{6,7,1,2};
    auto sol = Solution();
    std::cout << sol.increasingTriplet(nums) << "\n";
}