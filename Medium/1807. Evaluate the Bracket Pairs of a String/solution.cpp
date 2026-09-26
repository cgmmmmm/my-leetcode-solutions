#include <vector>
#include <unordered_map>
#include <string_view>
#include <string>

struct string_hash 
{
    using is_transparent = void;
    size_t operator()(std::string_view sv) const
    {
        return std::hash<std::string_view>{}(sv);
    }
    size_t operator()(const std::string& s) const
    {
        return std::hash<std::string>{}(s);
    }
};

class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) 
    {
        std::unordered_map<std::string, std::string, string_hash, std::equal_to<>> ump;
        for (const auto& vec : knowledge)
        {
            ump.emplace(vec[0], vec[1]);
        }

        int len = s.size();

        std::string res;
        int i = 0;
        while (i < len)
        {
            if (s[i] == '(')
            {
                int j=i;
                while (s[++j] != ')') {}

                std::string_view sub_view = std::string_view(s).substr(i+1, j-i-1);
                auto it = ump.find(sub_view);
                if (it != ump.end()) 
                    res.append(it->second);
                else 
                    res.push_back('?');
                i=j+1;
            }
            else
            {
                res.push_back(s[i]);
                i++;
            }
        }

        return res;
    }
};