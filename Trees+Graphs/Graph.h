#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphNode{
public:
    int value;
    vector<GraphNode*> adjacency;
    bool visited = false; //for DFS
    bool marked = false; //for BFS

public:
    GraphNode(int a): value(a) {}
};

class Graph{
public:
    vector<GraphNode*> nodes; 
};

void visit(GraphNode* g)
{
    cout << g->value;
}

void DFS(GraphNode* g)
{
    visit(g);
    g->visited = true;
    for (auto node : g->adjacency)
    {
        if (node->visited == false)
        {
            DFS(node);
        }
    }
}

void BFS(GraphNode* g)
{
    queue<GraphNode*> queue;
    g->marked = true;
    queue.push(g);
    visit(g);
    while(!queue.empty())
    {
        GraphNode* removed = queue.front();
        queue.pop();
        visit(removed);
        for (auto node : removed->adjacency)
        {
            if(!node->marked)
            {
                node->marked = true;
                queue.push(node);
            }
        }
    }
}

Graph* CreateGenericGraph(int nodes, int edges)
{
    Graph* graph = new Graph();
    for (int i = 0; i < nodes; i++)
    {
        GraphNode* node = new GraphNode(i);
        graph->nodes.push_back(node);
    }
    for (int i = 0; i< edges; i++)
    {
        int a = rand()%nodes;
        int b = rand()%nodes;
        bool alreadyPresent = std::find(graph->nodes[a]->adjacency.begin(), graph->nodes[a]->adjacency.end(), graph->nodes[b]) != graph->nodes[a]->adjacency.end();
        if (a != b && !alreadyPresent)
        {
            graph->nodes[a]->adjacency.push_back(graph->nodes[b]);
        }
    }

    return graph;
}

void PrintAdjacencyList(Graph* g)
{
    for (int i = 0; i < g->nodes.size();i++)
    {
        cout << i << ": ";
        for (auto node : g->nodes[i]->adjacency)
        {
            cout << node->value << ", ";
        }
        cout << endl;
    }
}