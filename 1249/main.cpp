#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        // look left to right on the string s
        // keep track of how many open parenthesis we have
        // if we have 0 and we face ), we discard it

        // If we get a delta > 0 at the end, we go backward 
        // and delete the open parenthesis

        
        std::vector<string::iterator> open_par {};
        std::vector<string::iterator> to_remove {};

        for (auto c = s.begin(); c != s.end(); ++c){

            if (*c == ')'){
                if (open_par.size() == 0)
                    to_remove.push_back(c);
                else
                    open_par.pop_back();
            }

            else if (*c == '(')
                open_par.push_back(c);
        }

        if (open_par.size() > 0)
        {
            for (const auto i: open_par)
            {
                to_remove.push_back(i);
            }
        }

        std::sort(to_remove.begin(), to_remove.end(), std::greater<std::string::iterator>());

        for (const auto& pos: to_remove)
            s.erase(pos);

        return s;
    }
};

int main()
{
    string s = "lee(t(c)o)de)";
    s = "))((";
    Solution sol;
    cout << sol.minRemoveToMakeValid(s);
}