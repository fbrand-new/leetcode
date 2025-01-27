// This one is slow.
// Best runtime is 0ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Actually complexity might be the same as far as the algo
// But implementation could be better


class SolutionSlow {
public:
    string gcdOfStrings(string str1, string str2) {
        
        // get the size of both strings
        auto size1 = str1.length();
        auto size2 = str2.length();

        // get all common divisors of sizes. 
        // mcd string must be a substring of that size being replicated for both strings
        auto divs1 = findDivisors(size1);
        auto divs2 = findDivisors(size2);
        auto commonDivs = findCommonDivisors(divs1, divs2);

        // using reverse iterator to traverse in reverse order
        for(auto num = commonDivs.rbegin(); num != commonDivs.rend(); ++num)
        {
            // create substr of both strings.
            // find all substrs occurences in og string
            // if num occurences*div is equal to str lenght for both, BANG!
            auto substr1 = str1.substr(0,*num);
            auto substr2 = str2.substr(0,*num);
            if(substr1 != substr2)
            {
                continue;
            }

            auto occ1 = 1;
            size_t pos = *num;
            while(true)
            {
                auto occ = str1.find(substr1,pos);
                if(occ != string::npos)
                {
                    occ1++;
                }
                else
                {
                    break;
                }
                pos = occ + (*num);
            }

            auto occ2 = 1;
            pos = *num;

            while(true)
            {
                auto occ = str2.find(substr2,pos);
                if(occ != string::npos)
                {
                    occ2++;
                }
                else
                {
                    break;
                }
                pos = occ + (*num);
            }

            if(occ1*(*num) == size1 && occ2*(*num) == size2)
            {
                return substr1;
            }
        }

        return "";
    }

    std::vector<size_t> findDivisors(size_t num1)
    {
        vector<size_t> divs{};

        for(size_t i = 1; i<=num1; i++)
        {
            if(num1%i == 0)
            {
                divs.push_back(i);
            }
        }

        return divs;
    }

    std::vector<size_t> findCommonDivisors(std::vector<size_t> div1, std::vector<size_t> div2)
    {
        std::vector<size_t> common_divs{};

        for(auto num: div1)
        {
            if(std::find(div2.begin(), div2.end(), num) != div2.end())
            {
                common_divs.push_back(num);
            }
        }

        return common_divs;
    }



};

class Solution {
    string gcdOfStrings(string str1, string str2) {



        return "";
    }
};

int main() {

    auto st1 = "ABCABC";
    auto st2 = "ABC";

    auto sol = Solution();
    auto res = sol.gcdOfStrings(st1,st2);

    cout << "res is " << res << "\n";
}