#include <iostream>
#include <fstream>
#include "linkedlist.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 3) {
    throw std::invalid_argument("Usage: ./bard <INPUT FILE> <OUTPUT FILE>");
  }

  ifstream ssFile;
  ifstream input;
  ofstream output;

  ssFile.open("shakespeare-cleaned5.txt");
  input.open(argv[1]);
  output.open(argv[2]);

  LinkedList wordList[100];

  string word;
  while (ssFile >> word) {
    int len = word.length();
    if (len > 0) {
      wordList[len].insert(word);
    }
  }

  for (int i = 0; i < 100; i++) {
    wordList[i].sort();
  }

  int length;
  int rank;

  while (input >> length >> rank) {
    if (length >= 100 || wordList[length].length() == 0) {
      output << "-" << endl;
    } else {
      output << wordList[length].find(rank) << endl;
    }
  }

  ssFile.close();
  input.close();
  output.close();

}