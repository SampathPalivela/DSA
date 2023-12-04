#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//CODE
class Pair{
	public:
	Node<int> *head, *tail;
	
};
Pair  construct(BinaryTreeNode<int>* root){
	if(root==NULL){
		Pair n;
		n.head=NULL;
		n.tail=NULL;
		return n;
	}
	if(root->left==NULL && root->right==NULL){
		Pair n;
		Node<int> * node = new Node<int>(root->data);
		n.head=node;
		n.tail= node;
		return n;
	}
	if(root->left==NULL){
		Pair n;
		Node<int> * node = new Node<int>(root->data);
		Pair right = construct(root->right);
		n.head=node;
		n.head->next= right.head;
		n.tail= right.tail;
		return n;
	}
	if(root->right==NULL){
		Pair n;
		Node<int> * node = new Node<int>(root->data);
		Pair left = construct(root->left);
		n.head=left.head;
		left.tail->next = node;
		n.tail=node;
		return n;
	}
	Pair left = construct(root->left);
	Pair right = construct(root->right);
	Node<int> * node = new Node<int>(root->data);
	left.tail->next= node;
	node->next=right.head;
	Pair n ;
	n.head=left.head;
	n.tail=right.tail;
	return n;

}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	Pair ans = construct(root);
	return ans.head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}