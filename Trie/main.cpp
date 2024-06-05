#include <iostream>
using namespace std;

class StreamChecker {
public:
    struct Node {
        Node* links[26];
        bool flag = false;

        bool itContains(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put (char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get (char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };
};

class Trie {
public:
    StreamChecker::Node* root;
    Trie() {
        root = new StreamChecker::Node();
    }
    void insert(string &str) {
        StreamChecker::Node* node = root;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (!node->itContains(str[i])) {
                node->put(str[i], new StreamChecker::Node());
            }
            node = node->get(str[i]);
        }
        node->setEnd();
    }

    bool check(string &str) {
        StreamChecker::Node* node = root;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (node->itContains(str[i])) {
                node = node->get(str[i]);
                if (node->isEnd()) {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }
};

class Solution {
Trie *trie;
string str;
public:
    void add (vector<string>& words) {
        trie = new Trie();
        for (auto word : words) {
            trie->insert(word);
        }
        str = "";
    }

    bool query(char letter) {
        str+=letter;
        return trie->check(str);
    }
};

int main() {
    Solution* obj = new Solution();
    vector<string> words = {"cd", "f", "kl"};
    obj->add(words);
    cout << obj->query('a') << endl;
    cout << obj->query('b') << endl;
    cout << obj->query('c') << endl;
    cout << obj->query('d') << endl;
    cout << obj->query('e') << endl;
    cout << obj->query('f') << endl;
    return 0;
}
