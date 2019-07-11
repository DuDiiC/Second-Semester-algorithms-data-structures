# Second Semester - Algorithms and data structures

Tasks from the laboratory: [__Algorithms and data structures__](https://usosweb.umk.pl/kontroler.php?_action=katalog2/przedmioty/pokazPrzedmiot&kod=1000-I1ASD). 

Tasks come from [ZawodyWeb](https://www.mat.umk.pl:8070/ZawodyWeb) or they are additionally asked by the lecturer. Many tasks come from the [UVa](https://uva.onlinejudge.org) website.

I used the __functional programing__ paradigm and the __C++14__ standard.

---

### Issues implemented during the course:

- sorting algorithms:
  - [radix sort](https://en.wikipedia.org/wiki/Radix_sort)
  - [bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)
- basic STL containers: stack, queue, deque, priority queue, list, set, map, vector
- greedy algorithms and dynamic programming: 
  - [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem)
  - [change-making problem](https://en.wikipedia.org/wiki/Change-making_problem)
- graph (and directed graph) representation methods:
  - adjacency matrix
  - incidence matrix
  - adjacency list
- graph traversal:
  - Depth First Search - [DFS](https://en.wikipedia.org/wiki/Depth-first_search)
  - Breadth First Search - [BFS](https://en.wikipedia.org/wiki/Breadth-first_search)
- [topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)
- Minimum Spanning Tree ([MST](https://en.wikipedia.org/wiki/Minimum_spanning_tree)):
  - [Prim's algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm)
  - [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)
  - [Borůvka's algorithm](https://en.wikipedia.org/wiki/Borůvka%27s_algorithm)
- [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman–Ford_algorithm)
- [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)
- [disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- maximum flow problem:
  - [Ford–Fulkerson algorithm](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm)
  - [Dinic's algorithm](https://en.wikipedia.org/wiki/Dinic%27s_algorithm)
- maximal matching in bigraf:
  - for example [hall's marriage theorem](https://en.wikipedia.org/wiki/Hall%27s_marriage_theorem)
- the least distant pair of points (as an example of [Divide and Conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm))
- [Convex hull](https://en.wikipedia.org/wiki/Convex_hull):
  - [Jarvis march/gift wrapping algorithm](https://en.wikipedia.org/wiki/Gift_wrapping_algorithm)
  - [Graham scan](https://en.wikipedia.org/wiki/Graham_scan)
- string-searching algorithms:
  - [Aho–Corasick algorithm](https://en.wikipedia.org/wiki/Aho–Corasick_algorithm)
  - [Boyer–Moore algorithm](https://en.wikipedia.org/wiki/Boyer–Moore_string-search_algorithm)
  - [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)
  
---

## Travelling salesman problem

As semester project I implemented a [heuristic](https://en.wikipedia.org/wiki/Heuristic_(computer_science)) solution to the travelling salesman problem ([TSP](https://en.wikipedia.org/wiki/Travelling_salesman_problem)).

To create the first path of the graph I used the [nearest neighbour algorithm](https://en.wikipedia.org/wiki/Nearest_neighbour_algorithm) - the salesman starts at a random city and repeatedly visits the nearest city until all have been visited. It quickly yields a short tour, but usually not the optimal one.

To improve the solution I used [2-OPT alghorithm](https://en.wikipedia.org/wiki/2-opt) - the main idea behind it is to take a route that crosses over itself and reorder it so that it does not.

I received a route algorithm about __10%__ longer than optimal.
