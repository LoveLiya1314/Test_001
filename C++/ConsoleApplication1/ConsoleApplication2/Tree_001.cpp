#include <iostream>
#include <stack>
struct BinTreeNode {
	char data;
	BinTreeNode *leftChild;
	BinTreeNode *rightChild;
};
void PreOrder(BinTreeNode *p) {
	if (p != NULL) {
		std::cout << p->data << " ";
		PreOrder(p->leftChild);
		PreOrder(p->rightChild);
	}
}

BinTreeNode *TableToBinary() {
	std::stack<BinTreeNode*> s;
	char ch;
	int k; 
	BinTreeNode *current, *newNode, *root;
	root = NULL;
	k = 1;
	std::cin >> ch;
	while (ch != '#') {
		switch (ch) {
		case '(': 
			s.push(newNode);
			k = 1;
			break;
		case ',':
			k = 2;
			break;
		case ')': 
			s.pop();
			break;
		default:
			newNode = new BinTreeNode();
			if (newNode == NULL) {
				std::cerr << "ERROR！\n";
				exit(1);
			}
			newNode->data = ch; 
			newNode->leftChild = newNode->rightChild = NULL;
			if (root == NULL) { 
				root = newNode;
			}
			else { 
				if (k == 1) { 
					current = s.top();
					current->leftChild = newNode;
				}
				else { 
					current = s.top();
					current->rightChild = newNode;
				}
			}
		} 
		std::cin >> ch;
	} 
	return root;
} 

BinTreeNode *CreateBinaryTree() {
	BinTreeNode *p;
	char ch;

	std::cin >> ch;
	if (ch == '#')
		return NULL;
	p = new BinTreeNode();
	p->data = ch;
	p->leftChild = CreateBinaryTree();
	p->rightChild = CreateBinaryTree();
	return p;
}

int main02(int argc, const char * argv[]) {
	BinTreeNode *root;
	root = TableToBinary();
	PreOrder(root);
	system("pause");
	return 0;
}
