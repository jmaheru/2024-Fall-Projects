#include "bfs.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_set>

void buildGraph(const string& filename, unordered_map<string, vector<pair<string, string>>>& graph) {
  ifstream file(filename);
  string line;

  while(getline(file, line)) {
    stringstream ss(line);
    string movie;
    ss >> movie;

    vector<string> actors;
    string actor;
    while (ss >> actor) {
      actors.push_back(actor);
    }

    //edges
    for (size_t i = 0; i < actors.size(); ++i) {
      for (size_t j = i + 1; j < actors.size(); ++j) {
        graph[actors[i]].emplace_back(actors[j], movie);
        graph[actors[j]].emplace_back(actors[i], movie);
      }
    }
  }
}

string findShortest(const unordered_map<string, vector<pair<string, string>>>& graph, const string& actor1, const string& actor2) {
  if (graph.find(actor1) == graph.end() || graph.find(actor2) == graph.end()) {
    return "Not present";
  }

  if (actor1 == actor2) {
    return actor1;
  }

  queue<string> q;
  unordered_map<string, pair<string, string>> parent; // Actor-> (parent, movie)
  unordered_set<string> visited;

  q.push(actor1);
  visited.insert(actor1);

  while(!q.empty()) {
    string current = q.front();
    q.pop();

    for (const pair<string, string>& neighbor : graph.at(current)) {
      const string& nectActor = neighbor.first;
      const string& movie = neighbor.second;

      if (!visited.count(nectActor)){
        visited.insert(nectActor);
        q.push(nectActor);
        parent[nectActor] = {current, movie};

        if (nectActor == actor2) {
          string path = actor2;
          string curr = actor2;

          while (curr != actor1) {
            pair<string, string> currentPair = parent[curr];
            string prevActor = currentPair.first;
            string movie = currentPair.second;
            path = prevActor + " -(" + movie + ")- " + path;
            curr = prevActor;
          }

          return path;
        }
      }
    }
  }
  
  return "Not present";
}