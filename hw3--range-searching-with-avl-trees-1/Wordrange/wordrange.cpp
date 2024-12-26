#include "bst.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 3){
    throw std :: invalid_argument("Usage: ./wordrange <INPUT FILE> <OUTPUT FILE>");
  }
  
  ifstream input;
  ofstream output;

  input.open(argv[1]);
  output.open(argv[2]);

  BST bst;
  string line;

  while (getline(input, line)) {
    istringstream iss(line);
    char command;
    iss >> command;

    if (command == 'i') {
      string word;
      iss >> word;
      bst.insert(word);
    } else if (command == 'r') {
      string str1;
      string str2;
      iss >> str1 >> str2;
      int count = bst.rangeQ(str1, str2);
      output << count << endl;
    }
  }

  input.close();
  output.close();

  return 0; // clears memeory

}