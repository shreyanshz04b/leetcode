class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(26, INT_MAX);
        for (string s : A) {
            vector<int> tmp(26, 0);
            for (char c : s) ++tmp[c - 'a'];
            for (int i = 0; i < 26; ++i) count[i] = min(count[i], tmp[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) 
            res.insert(res.end(), count[i], string(1, i + 'a'));
        return res;
    }
};
