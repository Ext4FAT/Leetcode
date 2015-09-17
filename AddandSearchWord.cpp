class TrieNode {
public:
	char c;
	map<char, TrieNode*> child;
	TrieNode(char character) {
		c = character;
	}
};

class Trie {
public:
	TrieNode* root;

	Trie() {
		root = new TrieNode('\0');
		end = new TrieNode('\0');
	}

	// Inserts a word into the trie.
	void insert(string word) {
		int i = 0;
		TrieNode *tmp, *child;
		for (i = 0, tmp = root; word[i]; i++){
			child = tmp->child[word[i]];
			if (!child){
				child = new TrieNode(word[i]);
				tmp->child[word[i]] = child;
			}
			tmp = child;
		}
		tmp->child[0] = end;
	}

	// Returns if the word is in the trie.
	bool search(string word, TrieNode* current, int i) {
		TrieNode* child = current->child[word[i]];
		if (!word[i]){
			if (child == end) return true;
			return false;
		}
		if (word[i] != '.'){
			if (child)   return search(word, child, i + 1);
			return false;
		}
		bool flag = false;
		for (map<char, TrieNode*>::iterator it = current->child.begin(); it != current->child.end(); it++)
			if (it->second)		flag |= search(word, it->second, i + 1);
		return flag;
	}
	
private:
	TrieNode* end;
};


class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		dictionary.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return dictionary.search(word, dictionary.root, 0);
	}
	
private:
	Trie dictionary;
};