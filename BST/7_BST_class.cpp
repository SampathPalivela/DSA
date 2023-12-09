#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



class BST {
   BinaryTreeNode<int> * root ;
   public:
    BST() { 
        root = NULL;
    }
    ~BST(){
        delete root;
    }

    
    private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int> * node){
        if(node==NULL){
            BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(data<=node->data){
            node->left = insert(data, node->left);
            return node;
        }
        if(data>node->data){
            node->right=insert(data, node->right);
            return node;
        }
    }

    bool search(int data, BinaryTreeNode<int>* node){
        if(node==NULL)return false;
        if(node->data==data)return true;
        if(data<node->data)return search(data, node->left);
        if(data>node->data)return search(data, node->right);
       
    }
    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int> * node){
        if(node==NULL){
            return NULL;
        }
       if(data<node->data){
           node->left = remove(data, node->left);
           return node;
       }
       if(data>node->data){
           node->right=remove(data, node->right);
       }
       if(!node->right && !node->left){
           delete node;
           return NULL;
       }
       if(!node->right){
           BinaryTreeNode<int> * temp = node->left;
           delete node;
           return temp;
       }
       if(!node->left){
           BinaryTreeNode<int> * temp = node->right;
           delete node;
           return temp;
       }
       BinaryTreeNode<int> * rightmin=node->right;
       while(rightmin->left){
           rightmin= rightmin->left;
       }
       node->data = rightmin->data;
       node->right = remove(rightmin->data, node->right);
       return node;
    }
    void print(BinaryTreeNode<int> * node){
        if(node==NULL)return;
        cout<<node->data<<':';
        if(node->left){
            cout<<"L:"<<node->left->data<<',';
        }
        if(node->right){
            cout<<"R:"<<node->right->data;
        }
        cout<<endl;
        print(node->left);
        print(node->right);

    }

    public:
    void remove(int data) { 
        root = remove(data,root);
    }

    void print() { 
        print(root);
    }

    void insert(int data) { 
        root = insert(data, root);
    }

    bool search(int data) {
		return search(data, root);
    }
};


int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}