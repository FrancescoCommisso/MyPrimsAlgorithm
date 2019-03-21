CREATES A MINIMUM SPANNING TREE FROM A GIVEN WEIGHTED GRAPH.

USAGE: Uses a variation of Prims Algorithm that I created.

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
