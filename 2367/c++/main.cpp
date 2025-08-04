#include <unordered_map>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        std::unordered_map<int,int> triplets;

        int n_triplets = 0;

        for(const int n: nums){

            triplets[n] = 1;

            if (n - diff >= 0 && triplets[n-diff] > 0) {
                triplets[n-diff] = 2;
            }

            if (n - 2*diff >= 0 && triplets[n-2*diff] == 2)
                n_triplets += 1;
        }

        for (const auto &[key,val]: triplets){
            cout << key << ":" << val << "\n";
        }

        return n_triplets;
    }
};

int main(){

    Solution sol;

    vector<int> test = {0,1,4,6,7,10};
    test = {4,5,6,7,8,9};
    int diff_test = 3;
    diff_test = 2;

    int res = sol.arithmeticTriplets(test, diff_test);

    cout << "n triplets: " << res << "\n";
}