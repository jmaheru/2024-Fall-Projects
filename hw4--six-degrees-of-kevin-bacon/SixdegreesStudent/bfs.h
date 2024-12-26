#ifndef BFS_H
#define BFS_H

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

void buildGraph(const string& filename, unordered_map<string, vector<pair<string, string>>>& graph);

string findShortest(const unordered_map<string, vector<pair<string, string>>>& graph, const string& actor1, const string& actor2);

#endif
