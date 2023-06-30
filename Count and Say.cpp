class Solution {
public:
   
        std::string countAndSay(int n) {
    if (n == 1)
        return "1";

    std::string prev = countAndSay(n - 1);
    std::string result;

    int count = 1;
    for (int i = 0; i < prev.size(); i++) {
        if (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
            count++;
        } else {
            result += std::to_string(count) + prev[i];
            count = 1;
        }
    }

    return result;

        
    }
};