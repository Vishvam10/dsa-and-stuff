class Trie {
private:
    struct Node {
        Node* children[26];
        bool is_end;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            is_end = false;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->is_end = true;
    }

    bool search(string word) {
        Node* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->is_end;
    }

    bool startsWith(string prefix) {
        Node* cur = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (cur->children[idx] == nullptr) {
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }
};