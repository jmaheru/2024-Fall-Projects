#include "bst.h"
#include <iostream>

using namespace std;

BST :: BST()
{
  root = NULL;
}

BST :: ~BST() {
  deleteBST(root);
}

void BST :: deleteBST(Node* node) {
  if (node == NULL) {
    return;
  }

  deleteBST(node->left);
  deleteBST(node->right);
  delete node;
}

void BST :: insert(string key) {
  root = insert(root, key);
}

Node* BST :: insert(Node* start, string key) {
  if (start == NULL) {
    return new Node(key);
  }

  if (key < start->key) {
    start->left = insert(start->left, key);
  } else if (key > start->key) {
    start->right = insert(start->right, key);
  }
  
  return start;
}

int BST :: rangeQ(const string& str1, const string& str2) {
  return rangeQ(root, str1, str2);
}

int BST :: rangeQ(Node* node, const string& str1, const string& str2) {
  if (node == NULL) {
    return 0;
  }

  if (node->key < str1) {
    return rangeQ(node->right, str1, str2);
  } else if(node->key > str2) {
    return rangeQ(node->left, str1, str2);
  } else {
    return 1 + rangeQ(node->left, str1, str2) + rangeQ(node->right, str1, str2);
  }
}