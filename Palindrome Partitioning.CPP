class Solution {
public:
   bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void backtrack(vector<vector<string>>& result, vector<string>& current, const string& s, int start) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i)) {
            current.push_back(s.substr(start, i - start + 1));
            backtrack(result, current, s, i + 1);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(const string& s) {
    vector<vector<string>> result;
    vector<string> current;

    backtrack(result, current, s, 0);

    return result;
}
};