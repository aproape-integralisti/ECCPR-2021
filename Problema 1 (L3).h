#include "Tree.h"

template <class T> void DFS(Node<T> *node, Node<T> *parent, int count, int &treeDiameter, Node<T> *&farthestNode) {
	if(treeDiameter < count) {
		treeDiameter = count;
		farthestNode = node;
	}

	for(auto neighbor : node->neighbors) {
		if(neighbor != parent) {
			DFS(neighbor, node, count + 1, treeDiameter, farthestNode);
		}
	}
}

template <class T> int getTreeDiameter(Tree<T> & myTree) {
	int treeDiameter = -1;
	Node<T> *farthestNode {};
	
	DFS(myTree.root, myTree.root, 1, treeDiameter, farthestNode);
	DFS(farthestNode, farthestNode, 1, treeDiameter, farthestNode);

	return treeDiameter;
}