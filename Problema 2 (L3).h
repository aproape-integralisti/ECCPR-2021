#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	bool isEndOfWord {};
	bool hasChild {};
	array<TrieNode *, 26> children {};

	TrieNode() = default;
	
	~TrieNode() {
	    for(auto &child : children) {
	        delete child;
	    }
	}
};

class Trie {
private:
    int size {};
	TrieNode *root {};
public:
	Trie() { root = new TrieNode(); }

	void insert(string const &inputString) {
		auto currentNode = root;

		for (auto const &c : inputString) {
			if (currentNode->children[c - 'a'] == nullptr) {
			    currentNode->hasChild = true;
				currentNode->children[c - 'a'] = new TrieNode();
			}

			currentNode = currentNode->children[c - 'a'];
			
			if(currentNode->isEndOfWord) {
				return;
			}
		}

	    if(currentNode->hasChild) {
	        return;
	    }

        size++;
		currentNode->isEndOfWord = true;
	}

	int getSize() const {
		return size;
	}
	
    ~Trie() {
        delete root;
	}
};