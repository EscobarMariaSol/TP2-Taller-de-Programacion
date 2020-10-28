#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include <set>
#include <stack>

class Dfs {

private:
    bool cycle;
    bool unusedInstructions;
    int visit(Graph& graph, Node& actual, std::set<Node>& visited);


public:
    Dfs();
    ~Dfs();
    int walkGraph(Graph& graph);
    bool hasCycle() const;
    bool hasUnusedInstructions() const;

};

#endif // DFS_H