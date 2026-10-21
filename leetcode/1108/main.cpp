class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char ch : address) ans += (ch == '.') ? "[.]" : string(1, ch);
        return ans;
    }
};
