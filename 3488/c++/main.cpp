#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <iterator>

using namespace std;

void print_vector(const vector<int>& v)
{
    for(const auto el: v)
        cout << el << ",";

    cout << "\n";
}

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> sol;

        std::unordered_map<int,std::map<int,int>> nums_t;

        // Insert nums element in a map so that we store their locations in original nums
        for(size_t i = 0; i < nums.size(); ++i)
            nums_t[nums[i]][i] = i; // for the main table save a map entry s.t. pos_map[i] = i

        // for(const auto &[key,val]: nums_t){

        //     cout << "["<< key << "] ";

        //     for(const auto el: val)
        //         cout << el << ",";

        //     cout << "\n";
        // }

        for(const auto pos: queries){
            int val = nums[pos];
            map<int,int>& idxs = nums_t[val];


            // cout << "idxs for query: " << pos << "\n";
            // print_vector(idxs);

            if (idxs.size() == 1)
                sol.push_back(-1);
            else {
                auto it = idxs.find(pos);
                int dist_next, dist_prev = 0;
                
                // // check boundary condition, since we want to wrap the vector
                if (it == idxs.begin()){
                    auto prev_it = std::prev(idxs.end());
                    dist_prev = (nums.size() - prev_it->first) + pos;  
                }
                else{
                    auto prev_it = std::prev(it);
                    dist_prev = pos - prev_it->first;
                }

                if (it == std::prev(idxs.end())){
                    auto next_it = idxs.begin();
                    dist_next = (nums.size() - pos) + next_it->first;
                }
                else{
                    auto next_it = std::next(it);
                    dist_next = next_it->first - pos;
                }
                 
                if (dist_next >= dist_prev)
                    sol.push_back(dist_prev);
                else
                    sol.push_back(dist_next);
            }

        }

        return  sol;
    }
};



int main()
{
    std::vector<int> nums = {1,3,1,4,1,3,2};
    std::vector<int> queries = {0,3,5};

    auto sol = Solution();
    
    auto res =  sol.solveQueries(nums, queries);

    for(const auto el: res)
        cout << el <<",";


}