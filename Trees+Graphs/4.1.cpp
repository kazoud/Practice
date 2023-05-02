#include "Graph.h"

bool RouteBetweenNodes(GraphNode* start, GraphNode* end)
{
    queue<GraphNode*> queue;
    start->marked = true;
    queue.push(start);
    while(!queue.empty())
    {
        GraphNode* front = queue.front();
        queue.pop();
        for (auto node : front->adjacency)
        {
            if (node == end)
            {
                return true;
            }
            if (!node->marked)
            {
                node->marked = true;
                queue.push(node);
            }
        }
    }
    return false;
}

int main()
{
    Graph* g = CreateGenericGraph(5,5);
    PrintAdjacencyList(g);
    cout << RouteBetweenNodes(g->nodes[3],g->nodes[4]) << endl;
}