#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

LinkedList :: LinkedList()
{
  head = NULL;
}

void LinkedList :: insert(const string& word) 
{
  Node *curr = head;

  while (curr != NULL){
    if (curr->word == word) {
      curr->frequency++;
      return;
    }
    curr = curr->next;
  }

  Node *to_add = new Node(word);
  to_add->word = word;

  to_add->next = head;
  head = to_add;

}

void LinkedList :: sort() 
{
  if (head == NULL || head->next == NULL){
    return;
  }

  Node *sorted = NULL; //new list that will be sorted

  Node *curr = head;

  while(curr != NULL){
    Node *next = curr->next;

    if (sorted == NULL || sorted->frequency < curr->frequency || (sorted->frequency == curr->frequency && sorted->word > curr->word)){
      curr->next = sorted;
      sorted = curr;
    } else {
      Node *temp = sorted;
      
      while (temp->next != NULL && (temp->next->frequency > curr->frequency || (temp->next->frequency == curr->frequency && temp->next->word < curr->word))){
        temp = temp->next;
      }

      curr->next = temp->next;
      temp->next = curr;
    }

    curr = next;
  }

  head = sorted;
}

string LinkedList :: find(int rank){
  Node *curr = head;
  int currRank = 0;

  while (curr != NULL) {
    if (currRank == rank) {
      return curr->word;
    }
    currRank++;
    curr = curr->next;
  }

  return "-"; //if not found
}

int LinkedList :: length()
{
  int length = 0;
  Node *curr = head;

  while (curr != NULL){
    length++;
    curr = curr->next;
  }

  return length;
}
