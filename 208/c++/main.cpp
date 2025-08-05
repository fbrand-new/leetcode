#include <cstddef>
#include <memory>
#include <string>
#include <map>
#include <memory>
#include <optional>
#include <iostream>

using namespace std;

class Trie {
public:
    std::map<string,Trie> trie;
    bool is_word = false;

    Trie() {
    }
    
    void insert(string word) {
        if (word.size() > 0)
            this->insertRec(1,word);
    }

    void insertRec(std::size_t i, string& word) {
        if (i == word.size()+1)
            this->is_word = true;
        if (i <= word.size())
            this->trie[word.substr(0,i)].insertRec(i+1,word);
    }
    
    bool search(string word) {

        if (this->trie.empty())
            return false; //empty trie

        if (word.empty())
            return false;

        const auto res = startsWithRec(1,word);

        if (res){
            return res->is_word;
        }
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        
        if (this->trie.empty())
            return false; //empty trie

        if (prefix.empty())
            return false;

        auto res = startsWithRec(1, prefix);
        if (res.has_value()){
            if (res->trie.empty() && !res->is_word)
                return false;
            else
                return true;
        }
        else
            return false;
    }

    const std::optional<Trie> startsWithRec(size_t i, string prefix) {
        
        string curr_pre = prefix.substr(0,i);

        // cout << "Analyzing branch with prefix: " << curr_pre << "\n";

        if (i == prefix.size())
            return this->trie[prefix];

        // string curr_pre = prefix.substr(0,i);

        if (this->trie.find(curr_pre) != this->trie.end()){
            // cout << "found branch with prefix: " << curr_pre << "\n";
            return this->trie[curr_pre].startsWithRec(i+1, prefix);
        }
        else{
            // cout << "not found branch with prefix: " << curr_pre << "\n";
            return {};
        }
    }

};

ostream& operator<<(ostream& os, const Trie& tr) {
    for (const auto& [key,_]: tr.trie)
        os << key << ",";
    return os << tr.is_word << "\n";
}

int main(){
    std::unique_ptr<Trie> trie = std::make_unique<Trie>(Trie());
    trie->insert("hello");
    auto res = trie->startsWith("helloa");
    cout << "\n";
    cout << res << "\n";
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */