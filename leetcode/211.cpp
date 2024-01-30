#include <bits/stdc++.h>

using namespace std;

struct Trie {
    vector<Trie *> child;
    bool isEnd;
    Trie() {
        this->child = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(Trie *root, const string &word) {
    Trie *node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new Trie();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
  public:
    WordDictionary() { trie = new Trie(); }

    void addWord(string word) { insert(trie, word); }

    bool search(string word) { return dfs(word, 0, trie); }

    bool dfs(const string &word, int index, Trie *node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            Trie *child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                Trie *child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
    Trie *trie;
};
