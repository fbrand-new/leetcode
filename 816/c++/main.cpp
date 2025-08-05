#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        
        std::vector<string> coords;

        for (std::size_t i = 1; i < s.size() - 2; ++i){
            string first_coord = s.substr(1,i);
            string second_coord = s.substr(i+1,s.size()-i-2);
            
            cout << "first_coord:" << first_coord << std::endl;
            cout << "second_coord:" << second_coord << std::endl;

            std::vector<string> fs = buildCoord(first_coord);
            std::vector<string> secs = buildCoord(second_coord);
            

            for(const auto f: fs){
                for(const auto s: secs){
                    cout << "(" << f + ", " + s << ")" << "\n";
                    coords.push_back('(' + f + ", " + s + ')');
                }
            }

        }

        return coords;
    }

    vector<string> buildCoord(string& s)
    {
        
        vector<string> out;
        
        int n = s.size();

        if (n == 1){
            out.push_back(s);
            return out;
        }

        for (size_t k = 1; k < n; ++k){
            // cout << s << std::endl;
            if (s[0] == '0'){
                s.insert(s.begin() + 1,'.');
                if (isValid(s)){
                    out.push_back(s);
                }
                return out;
            }
            else{
                string tmp = s;
                tmp.insert(tmp.begin() + k, '.');
                // cout << tmp << std::endl;
                if (isValid(tmp))
                    out.push_back(tmp);
            }
            

        }

        out.push_back(s);
        return out;
    }

    bool isValid(string& s){
        if (s.size() == 1)
            return true;
        else if (s[s.size()-1] == '0')
            return false;
        else
            return true;
    }
};

int main(){

    string test = "(0123)";

    auto sol = Solution();

    sol.ambiguousCoordinates(test);
}