#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

/*
        USAGE:  Uses a variation of Prims Algorithm that I created. 

                Works on Adjacency matrix of graph instead of
                updating fields in the graph object.
                (kinda redundant but I wanted to play with Adjacency Matrices) 

        STEPS:

            1.  Create a new Graph Struct with createGraph(numberOfVertices)
            
                    -   returns a Graph.
            
            2.  Add edges to the graph with addEdge(srcOfEdge,destOfEdge,ponterToGraph) 

                    -   return nothing but the uses the pointer to add edges
                        Graph it points to.
            
            3.  Create Adjacency Matrix using createAdjacencyMatrix(graph)
                    
                    -   pass the actual graph struct into the function
                    -   returns a vector<vector<int> > (A 2d vector of ints).
            
            4. Use mst(adjacencyMatrix)

                    -   This will create a new graph which is a 
                        minimum spanning tree of the original graph
                    -   This will also print the edges of the mst
                        and the weight of the whole mst.

            See main() for examples.
            
*/

struct Edge
{  
    int src;
    int dest;
    int weight;
};

struct Graph
{
    vector<int> vertices;
    vector<Edge> edges;
};

Graph createGraph(int v)
{
    Graph graph;
    for (int i = 0; i < v; i++)
    {
        graph.vertices.push_back(i);
    }
    return graph;
}
void printGraph(Graph g)
{
    cout << "Vertices: " << endl;
    for (int i = 0; i < g.vertices.size(); i++)
    {
        cout << g.vertices.at(i) << endl;
    }
    cout << "Edges: " << endl;
    for (int i = 0; i < g.edges.size(); i++)
    {
    cout << g.edges.at(i).src << " -- " << g.edges.at(i).dest << " == " << g.edges[i].weight << endl;
    }
}

int weighGraph(Graph g){
    int sum = 0;
    for(int i = 0; i<g.edges.size();i++){
        sum += g.edges[i].weight;
    }
    return sum;
}

void printMST(Graph g)
{
    cout << "The edges in the minimum spanning tree are: " << endl;
    for (int i = 0; i < g.edges.size(); i++)
    {
        cout << g.edges.at(i).src << " -- " << g.edges.at(i).dest << " == " << g.edges[i].weight << endl;
    }

    cout << "Total Weight is: " << weighGraph(g) << endl; 
}

void addEdge(int src, int dest, int weight, Graph *p)
{
    Edge e;
    e.dest = dest;
    e.src = src;
    e.weight = weight;
    p->edges.push_back(e);
}

vector<vector<int> > createAdjacenctVec(Graph g)
{
    int s = g.vertices.size();
    vector<vector<int> > result(s);

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            result[i].push_back(0);
        }
    }

    for(int i = 0; i<g.edges.size();i++){
        int x = g.edges[i].src;
        int y = g.edges[i].dest;
        result[x][y] = g.edges[i].weight;
        result[y][x] = g.edges[i].weight;
    }


    return result;
}

void printAdjacencyVector(vector<vector<int> > v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << v[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool hasElement(vector<int> v, int e){
    if(std::find(v.begin(), v.end(), e) != v.end()) {
        return true;
    } 
    return false;

}

void mst(vector<vector<int> > v){
    Graph g = createGraph(v.size());
    Graph *p = &g;
    vector<Edge> edges;

    vector<int> vistedVertices;    
    vistedVertices.push_back(0);
    while(vistedVertices.size()< v.size()){
        int src = INT_MAX;
        int dest = INT_MAX;
        int weight = INT_MAX;
        for (int i = 0; i< v.size();i++){
            if(hasElement(vistedVertices,i)){
                for (int j = 0; j< v.size();j++){
                    if ((v[i][j] < weight) && (v[i][j] > 0) && !(hasElement(vistedVertices,j) )){
                        src = i;
                        dest = j;
                        weight =v[i][j];
                    }
                }
            }
        }
        if(dest != INT_MAX && src != INT_MAX){
            vistedVertices.push_back(dest);
            addEdge(src,dest,weight,p);
        }
    }
    printMST(g);
}

int main()
{
    Graph g1 = createGraph(4);
    Graph *p1 = &g1; 
    addEdge(0, 1, 5, p1);
    addEdge(0, 2, 3, p1);
    addEdge(0, 3, 2, p1);
    addEdge(1, 3, 7, p1);
    addEdge(2, 3, 2, p1);
    vector<vector<int> > v1 = createAdjacenctVec(g1);
        printAdjacencyVector(v1);

    mst(v1);

    // Graph g = createGraph(5);
    // Graph *p = &g; 
    // addEdge(0, 1, 6, p);
    // addEdge(0, 4, 7, p);
    // addEdge(1, 2, 2, p);
    // addEdge(2, 4, 3, p);
    // addEdge(3, 4, 9, p);
    // vector<vector<int> > v = createAdjacenctVec(g);
    // mst(v);
    //


    // Graph g2 = createGraph(6);
    // Graph *p2 = &g2; 
    // addEdge(0, 1, 2, p2);
    // addEdge(0, 5, 81, p2);
    // addEdge(1, 4, 13, p2);
    // addEdge(1, 3, 3, p2);
    // addEdge(1, 2, 2, p2);
    // addEdge(2, 3, 9, p2);
    // addEdge(5, 4, 7, p2);
    // vector<vector<int> > v2 = createAdjacenctVec(g2);
    // mst(v2);

    // Graph g3 = createGraph(9);
    // Graph *p3 = &g3; 
    // addEdge(0, 1, 8, p3);
    // addEdge(0, 2, 12, p3);
    // addEdge(1, 2, 13, p3);
    // addEdge(1, 3, 25, p3);
    // addEdge(1, 4, 9, p3);
    // addEdge(2, 3, 14, p3);
    // addEdge(2, 6, 21, p3);
    // addEdge(3, 4, 20, p3);
    // addEdge(3, 5, 8, p3);
    // addEdge(3, 6, 12, p3);
    // addEdge(3, 7, 12, p3);
    // addEdge(3, 8, 16, p3);
    // addEdge(4, 5, 19, p3);
    // addEdge(5, 7, 11, p3);
    // addEdge(6, 8, 11, p3);
    // addEdge(7, 8, 9, p3);

    // vector<vector<int> > v3 = createAdjacenctVec(g3);
    // printAdjacencyVector(v3);
    // mst(v3);
    return 0;
}

