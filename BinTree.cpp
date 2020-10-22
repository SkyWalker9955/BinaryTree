
#include <iostream>
#include <array>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left, * right;
};

class Tree {

private:
    TreeNode* root;
public:
    void initTree();
    TreeNode* makeTreeNode(int data);
    void setLeft(TreeNode* N, int num);
    void setRight(TreeNode* N, int num);
    void buildTree(int arr[]);
    void inOrder(TreeNode* N);
};
////////////////////////////////////////////
void Tree::initTree() 
{
    this->root = NULL;
}

TreeNode* Tree::makeTreeNode(int data)
{
    TreeNode* Node = new TreeNode;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    
    return Node;
}

void Tree::setLeft(TreeNode* N, int num)
{
    if (N->left != NULL) {
        cout << "Error: left node already exists" << endl;
    }
    else {
        N->left = makeTreeNode(num);
    }
}

void Tree::setRight(TreeNode* N, int num)
{
    if (N->right != NULL) {
        cout << "Error: right node already exists" << endl;
    }
    else {
        N->right = makeTreeNode(num);
    }
}

void Tree::inOrder(TreeNode* N)
{
    //Go left
    if (N->left != NULL) {
        inOrder(N->left);
    }

    //Visit root
    cout << N->data << endl;

    //Go right 
    if (N->right != NULL) {
        inOrder(N->right);
    }
}

void Tree::buildTree(int arr [])
{
    initTree();
    int i;
    
    for (i = 0; i < 8; i++) {
        int temp = arr[i];

        //create the root tree
        if (root == NULL) {
            root = makeTreeNode(temp);
        }
        else {
            //find numbers position in the tree
            TreeNode* curr = new TreeNode;
            curr = root;
            ///////////////////////////
            bool searching = true;

            while (searching) {
                if (temp < curr->data) {
                    if (curr->left != NULL) {
                        curr = curr->left;
                    }
                    else {
                        searching = false;
                    }
                }
                else {
                    if (curr->right != NULL) {
                        curr = curr->right;
                    }
                    else {
                        searching = false;
                    }
                }
            }//end while searching 
            
            //Add number into a tree
            if (temp < curr->data) {
                setLeft(curr, temp);
            }
            else {
                setRight(curr, temp);
            }
        }
    }
    inOrder(root);
}

///////////////////////////////////////////////////////

int main()
{
    Tree K;
    int arr [8] = {4,6,5,8,7,9,1,11};
    K.buildTree(arr);
}
