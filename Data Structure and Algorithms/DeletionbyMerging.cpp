#include <iostream>
using namespace std;

struct TreeNode {
  int item;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data): item(data), left(nullptr), right(nullptr){}
};

TreeNode* root;

void inOrderTraversal(TreeNode* root){
  if(root != nullptr){
    inOrderTraversal(root->left);
    cout << root->item << "  ";
    inOrderTraversal(root->right);
  }
}

TreeNode* findLargestFromLeft(TreeNode* root){
  TreeNode* current = root->left;
  while(current->right != nullptr){
    current = current->right;
  }
  return current;
}

void deleteByMerging(TreeNode* deletedNode){
    if(deletedNode == root){
        TreeNode* temp = deletedNode->left;
        TreeNode* largest = findLargestFromLeft(deletedNode);
          largest->right = deletedNode->right;
          delete deletedNode;
          root = temp;
    }

    










}


int main(){

  TreeNode* node1 = new TreeNode(10);
  TreeNode* node2 = new TreeNode(6);
  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(8);
  TreeNode* node5 = new TreeNode(13);
  TreeNode* node6 = new TreeNode(11);
  TreeNode* node7 = new TreeNode(15);
  node1->left = node2;    node1->right = node5;
  node2->left = node3;     node5->left = node6;
  node2->right = node4;    node5->right = node7;
  root = node1;

  inOrderTraversal(root);

  cout << "\nLargest from the left : " << findLargestFromLeft(root)->item;
  cout << endl;
  deleteByMerging(root);
  inOrderTraversal(root);


  return 0;
}