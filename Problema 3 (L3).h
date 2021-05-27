#include "AVLTree.h"

template <class T> int getHeight(AVLNode<T> *root) {
	return (root == nullptr ? 0 : root->height);
}

template <class T> int getBalanceFactor(AVLNode<T> *root) {
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

template <class T> AVLNode<T> *insert(AVLNode<T> *root, T const &newKey) {
	if(root == nullptr) {
		return new AVLNode<T> (newKey, 1);
	}

	if(newKey < root->key) {
		root->left = insert(root->left, newKey);
	}

	if(root->key < newKey) {
		root->right = insert(root->right, newKey);
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	return fixViolation(root);
}

template <class T> void insert(AVLTree<T> &myAVLTree, T const &newKey) {
	myAVLTree.root = insert(myAVLTree.root, newKey);
}