# Second Semester - Algorithms and data structures

Tasks from the laboratory: __Algorithms and data structures__. 

Tasks come from https://www.mat.umk.pl:8070/ZawodyWeb or they are additionally asked by the lecturer. Many tasks come from the https://uva.onlinejudge.org website.

I used the functional programing paradigm and the c++ 14 standard.

### Issues implemented during the course:

- sorting algorithms:
  > radix sort,
  > bucket sort
- basic STL containers:
  > stack, 
  > queue,
  > deque, 
  > priority queue,
  > list, 
  > set, 
  > map,
  > vector
- greedy algorithms and ynamic programming: 
  > discrete knapsack problem, 
  > change-making problem
- graph (and directed graph) representation methods:
  > adjacency matrix,
  > incidence matrix,
  > adjacency list
- graph traversal:
  > Depth First Search - DFS,
  > Breadth First Search - BFS
- topological sorting
- Minimum Spanning Tree (MST):
  > Prim's algorithm,
  > Kruskal's algorithm, 
  > Borůvka's algorithm
- Bellman–Ford algorithm
- Floyd–Warshall algorithm
- disjoint-set data structure
- maximum flow problem:
  > Ford–Fulkerson algorithm,
  > Dinic's algorithm
- maximal matching in bigraf:
  > for example hall's marriage theorem
- the least distant pair of points
- Convex hull:
  > Jarvis march/gift wrapping algorithm,
  > Graham scan
- string-searching algorithms:
  > Aho–Corasick algorithm,
  > Boyer–Moore algorithm,
  > Knuth–Morris–Pratt algorithm
  
### As semester project I implemented a heuristic solution to the traveling salesman problem (TSP).

To create the first path of the graph I used _the nearest neighbour algorithm_ - the salesman starts at a random city and repeatedly visits the nearest city until all have been visited. It quickly yields a short tour, but usually not the optimal one.

To improve the solution I used _2-OPT alghorithm_ - the main idea behind it is to take a route that crosses over itself and reorder it so that it does not.

I received a route algorithm about __10%__ longer than optimal.
