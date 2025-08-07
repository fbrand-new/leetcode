#include <cmath>
#include <sys/types.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        // start searching from start left and right, once you find an el, return dist
        int first_stop = std::min(ulong(start),nums.size()-start);

        cout << first_stop;
        for(std::size_t i = 0; i < first_stop; ++i)
        {
            if (nums[start + i] == target)
                return i;
            else if (nums[start - i] == target)
                return i;
        }
#include <cmath>
#include <sys/types.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        // start searching from start left and right, once you find an el, return dist
        int first_stop = std::min(ulong(start),nums.size()-1-start);

        cout << first_stop;
        for(std::size_t i = 0; i <= first_stop; ++i)
        {
            if (nums[start + i] == target)
                return i;
            else if (nums[start - i] == target)
                return i;
        }

        if (start < nums.size()/2)
        {
            for(std::size_t i = first_stop; i < nums.size(); ++i)
                if(nums[start+i] == target)
                    return i;
        }
        else {
            for(std::size_t i = first_stop; i <= start; ++i)
                if(nums[start-i] == target)
                    return i;
        }

        return 0;
    }
};
        if (start < nums.size()/2)
        {
            for(std::size_t i = first_stop; i < nums.size(); ++i)
                if(nums[start+i] == target)
                    return i;
        }
        else {
            for(std::size_t i = first_stop; i <= start; ++i)
                if(nums[start-i] == target)
                    return i;
        }

        return 0;
    }
};