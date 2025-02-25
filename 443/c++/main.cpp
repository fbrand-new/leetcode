#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars) {
            char curr_char{};
            size_t counter = 0;
            for(auto it = chars.begin(); it != chars.end();)
            {
                if(*it != curr_char)
                {
                    curr_char = *it; //Update curr char before leaving it
                    if(counter>1) //We are not at the beginning so we write
                    {
                        string counter_string = std::to_string(counter);
                        for(auto c: counter_string)
                        {
                            it = chars.insert(it,c);
                            it++;
                        }
                    }

                    ++it;
                    counter = 1;
                }
                else 
                {
                    it = chars.erase(it);
                    counter += 1;
                }
            }

            if(counter > 1)
            {
                string counter_string = std::to_string(counter);
                for(auto c: counter_string)
                {
                    chars.push_back(c);
                }
            }
            return chars.size();
        }
    };
int main()
{
    vector<char> chars{'a','a','b','b','c','c','c'};
    vector<char> 
    auto sol = Solution{};
    cout << sol.compress(chars);
}