#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        // modifying flowerbed by padding beginning and end to account for only 2 places
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);

        // scan the flowerbed. For every set of 3 consecutives 0 you have a plot. Then up 1 every 2 plots
        int count{0};
        int consecutive_zeros{0};
        for(size_t i =0; i<flowerbed.size(); ++i){
            if(flowerbed[i] == 1)
            {
                consecutive_zeros = 0;
            } 
            else {
                consecutive_zeros += 1;
            }

            if(consecutive_zeros >= 3 && (consecutive_zeros-3)%2 == 0)
            {
                count += 1;
            }
        }

        if (count >= n)
        {
            return true;
        }

        return false;
    }
};


int main(){

    vector<int> test{1,0,0,0,1};
    vector<int> test2{0,0,1,0,1};
    int n{1};
    Solution sol;
    auto res = sol.canPlaceFlowers(test2,n);

    cout << res << "\n";


}