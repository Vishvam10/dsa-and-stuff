class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        stringstream ss(s);
        string token;
        int i = 1;
        while(ss >> token) {
            if(token.starts_with(w)) return i;
            i++;
        }
        return -1;
    }
};
