class TrieNode {
public:
    // Initialize your data structure here.
    char c;
    map<char,TrieNode*> child;
    TrieNode(char character) {
        c = character;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode('\0');
        end = new TrieNode('\0');
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        int i;
        TrieNode *tmp, *child;
        for(i = 0, tmp = root; word[i]; i++, tmp = child){
            child = tmp->child[word[i]];
            if(!child){
                child = new TrieNode(word[i]);
                tmp->child[word[i]]=child;
            }
        }
        tmp->child[0]=end;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i;
        TrieNode *tmp, *child;
        for(i = 0, tmp = root; word[i]; i++, tmp = child){
            child = tmp->child[word[i]];
            if(!child)  return false;
        }
        if(tmp->child[0] == end)  return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i;
        TrieNode *tmp, *child;
        for(i = 0, tmp = root; prefix[i]; i++, tmp=child){
            child=tmp->child[prefix[i]];
            if(!child)  return false;
        }
        return true;
    }

private:
    TrieNode* root;
    TrieNode* end;
};