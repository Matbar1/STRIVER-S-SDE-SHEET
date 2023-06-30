class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    int start = 0;
    unordered_set<char> seen;

    for (int end = 0; end < n; end++) {
        char current = s[end];
        while (seen.find(current) != seen.end()) {
            seen.erase(s[start]);
            start++;
        }
        seen.insert(current);
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}
};




        
        
    