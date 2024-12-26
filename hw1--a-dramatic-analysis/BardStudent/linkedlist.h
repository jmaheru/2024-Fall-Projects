#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

struct Node
{
  string word;
  int frequency;

  Node *next;

  Node(string w){
    word = w;
    frequency = 1;
    next = nullptr;
  }
};

class LinkedList
{
  private:
    Node *head;
  public:
    LinkedList();
    void insert(const string& word);
    void sort();
    string find(int);
    int length();
};

#endif