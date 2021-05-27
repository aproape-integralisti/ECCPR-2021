#include "AVLTree.h"

template<class T> T getMax(AVLNode<T> *root) {
	return (root->right == nullptr ? root->key : getMax(root->right));
}

template<class T> int getHeight(AVLNode<T> *root) {
	return (root == nullptr ? 0 : root->height);
}

template<class T> int getBalanceFactor(AVLNode<T> *root) {
	return (root == nullptr ? 0 : getHeight(root->left) - getHeight(root->right));
}

template <class T> AVLNode<T> *fixViolation (AVLNode<T> *root) {
    if(root == nullptr) {
        return nullptr;
    }
    
    if (getBalanceFactor(root) < -1 && getBalanceFactor(root->right) <= 0) {
		auto newRoot = root->right;

		root->right = newRoot->left;
		newRoot->left = root;

		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

		return newRoot;
	}
	
	if (getBalanceFactor(root) > 1 && getBalanceFactor(root->left) >= 0) {
		auto newRoot = root->left;

		root->left = newRoot->right;
		newRoot->right = root;

		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

		return newRoot;
	}
	
	if (getBalanceFactor(root) < -1 && getBalanceFactor(root->right) > 0) {
		auto newRoot = root->right->left;

		root->right->left = newRoot->right;
		newRoot->right = root->right;
		root->right = newRoot->left;
		newRoot->left = root;

		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		newRoot->right->height = 1 + max(getHeight(newRoot->right->left), getHeight(newRoot->right->right));
		newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

		return newRoot;
	}
	
	if (getBalanceFactor(root) > 1 && getBalanceFactor(root->left) < 0) {
		auto newRoot = root->left->right;

		root->left->right = newRoot->left;
		newRoot->left = root->left;
		root->left = newRoot->right;
		newRoot->right = root;

		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		newRoot->left->height = 1 + max(getHeight(newRoot->left->left), getHeight(newRoot->left->right));
		newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

		return newRoot;
	}
	
	return root;
}

template<class T> AVLNode<T> *erase(AVLNode<T> *root, T const &keyToBeErased) {
	if (root == nullptr) {
		return nullptr;
	}

	if (keyToBeErased < root->key) {
		root->left = erase(root->left, keyToBeErased);
	}

	if (root->key < keyToBeErased) {
		root->right = erase(root->right, keyToBeErased);
	}

	if (!(keyToBeErased < root->key) && !(root->key < keyToBeErased)) {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			return nullptr;
		}

		if (root->left == nullptr) {
			auto newRoot = root->right;
			delete root;
			return newRoot;
		}

		if (root->right == nullptr) {
			auto newRoot = root->left;
			delete root;
			return newRoot;
		}

		auto newKey = getMax(root->left);
		root->key = newKey;
		root->left = erase(root->left, newKey);
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	return fixViolation(root);
}

template<class T> AVLNode<T> *insert(AVLNode<T> *root, T const &newKey) {
	if (root == nullptr) {
		return new AVLNode<T>(newKey, 1);
	}

	if (newKey < root->key) {
		root->left = insert(root->left, newKey);
	}

	if (root->key < newKey) {
		root->right = insert(root->right, newKey);
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	return fixViolation(root);
}

template<class T> void insert(AVLTree<T> &myAVLTree, T const &newKey) {
	myAVLTree.root = insert(myAVLTree.root, newKey);
}

template<class T> void erase(AVLTree<T> &myAVLTree, T const &keyToBeErased) {
	myAVLTree.root = erase(myAVLTree.root, keyToBeErased);
}