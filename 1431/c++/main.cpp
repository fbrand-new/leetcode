#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        vector<bool> res;
        res.resize(candies.size(),true);

        // compute max
        auto m = *max_element(candies.begin(),candies.end());

        // rescale vector to max - vector + extraCandies
        // Count the numbers > 0. Can be merged with the step before
        for(size_t i=0; i<candies.size();++i)
        {
            if(candies[i] - m +extraCandies < 0)
            {
                res[i] = false;
            }
        }

        return res;

    }
};

int main(){
    vector<int> candies{1,2,3,4};
    int extra_candies{1};
    Solution sol{};

    auto res = sol.kidsWithCandies(candies,extra_candies);
    for(auto r: res){
        cout << r << '\n';
    }
}