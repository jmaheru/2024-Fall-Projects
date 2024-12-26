#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bfs.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc < 3){
    throw std :: invalid_argument("Usage: ./sixdegrees <INPUT FILE> <OUTPUT FILE>");
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);

  unordered_map<string, vector<pair<string, string>>> graph;
  buildGraph("cleaned_movielist.txt", graph);

  string line;

  while (getline(input, line)) {
    stringstream ss(line);
    string actor1, actor2;
    ss >> actor1 >> actor2;

    string results = findShortest(graph, actor1, actor2);
    output << results << endl;
  }

  input.close();
  output.close();

  return 0;
}