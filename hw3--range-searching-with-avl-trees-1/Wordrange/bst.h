#ifndef BST_H
#define BST_H

#include <string>
#include <vector>

using namespace std;

class Node 
{
  public:
    string key;
    Node* left;
    Node* right;

    Node(string val) {
      key = val;
      left = NULL;
      right = NULL;
    }
};

class BST
{
  private: 
    Node* root;

    Node* insert(Node* node, string key);
    int rangeQ(Node* node, const string& str1, const string& str2);
    void deleteBST(Node* node);

  public:
    BST();
    ~BST();
    void insert(string key);
    int rangeQ(const string& str1, const string& str2);
};

#endif