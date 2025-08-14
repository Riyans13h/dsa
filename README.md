# 📊 Algorithm Time & Space Complexity Cheat Sheet

This document contains a quick reference table for **time complexity** and **space complexity** of common algorithms across **searching, sorting, dynamic programming (DP), trees, graphs, strings, number theory, geometry, greedy algorithms, divide & conquer**, and more.

---

##  Legend
- **Best** → Best case time complexity
- **Avg** → Average case time complexity
- **Worst** → Worst case time complexity
- **Space** → Space complexity

---

| Category | Algorithm | Best | Avg | Worst | Space | Notes |
|----------|-----------|------|-----|-------|-------|-------|
| **Searching** | Linear Search | O(1) | O(n) | O(n) | O(1) | Works on unsorted data |
|  | Binary Search | O(1) | O(log n) | O(log n) | O(1) | Requires sorted data |
|  | Interpolation Search | O(1) | O(log log n) | O(n) | O(1) | Uniformly distributed data |
|  | Jump Search | O(√n) | O(√n) | O(√n) | O(1) | Sorted arrays |
| **Sorting** | Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Stable |
|  | Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Stable |
|  | Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | Not stable |
|  | Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Stable |
|  | Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | Not stable |
|  | Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | Not stable |
|  | Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | k = range |
|  | Radix Sort | O(nk) | O(nk) | O(nk) | O(n+k) | k = digits |
|  | Bucket Sort | O(n+k) | O(n) | O(n²) | O(n) | Uniform distribution |
| **DP** | Fibonacci (Top-Down) | O(n) | O(n) | O(n) | O(n) | Memoization |
|  | Fibonacci (Bottom-Up) | O(n) | O(n) | O(n) | O(1) | Tabulation |
|  | LCS | O(n·m) | O(n·m) | O(n·m) | O(n·m) | |
|  | Knapsack (0/1) | O(n·W) | O(n·W) | O(n·W) | O(n·W) | W = capacity |
|  | Matrix Chain Multiplication | O(n³) | O(n³) | O(n³) | O(n²) | |
|  | Edit Distance | O(n·m) | O(n·m) | O(n·m) | O(n·m) | |
|  | LIS | O(n²) | O(n²) | O(n²) | O(n) | Can be O(n log n) |
| **Trees** | DFS | O(n) | O(n) | O(n) | O(h) | h = height |
|  | BFS | O(n) | O(n) | O(n) | O(w) | w = width |
|  | AVL Tree Ops | O(log n) | O(log n) | O(log n) | O(n) | Self-balancing BST |
|  | Red-Black Tree Ops | O(log n) | O(log n) | O(log n) | O(n) | Balanced BST |
| **Graphs** | BFS | O(V+E) | O(V+E) | O(V+E) | O(V) | |
|  | DFS | O(V+E) | O(V+E) | O(V+E) | O(V) | |
|  | Dijkstra (Binary Heap) | O((V+E) log V) | O((V+E) log V) | O((V+E) log V) | O(V+E) | |
|  | Dijkstra (Fibonacci Heap) | O(E + V log V) | O(E + V log V) | O(E + V log V) | O(V+E) | |
|  | Bellman-Ford | O(V·E) | O(V·E) | O(V·E) | O(V) | Neg. weights |
|  | Floyd-Warshall | O(V³) | O(V³) | O(V³) | O(V²) | All pairs |
|  | Kruskal’s MST | O(E log E) | O(E log E) | O(E log E) | O(V+E) | Union-Find |
|  | Prim’s MST | O(E log V) | O(E log V) | O(E log V) | O(V+E) | |
|  | Topological Sort | O(V+E) | O(V+E) | O(V+E) | O(V) | DAG |
|  | Tarjan’s SCC | O(V+E) | O(V+E) | O(V+E) | O(V) | |
| **Strings** | Naive Search | O(m·n) | O(m·n) | O(m·n) | O(1) | |
|  | KMP | O(m+n) | O(m+n) | O(m+n) | O(m) | |
|  | Rabin-Karp | O(m+n) | O(m+n) | O(m·n) | O(1) | |
|  | Z-Algorithm | O(m+n) | O(m+n) | O(m+n) | O(m+n) | |
|  | Boyer-Moore | O(n/m) | O(n) | O(m·n) | O(1) | |
| **Number Theory** | Sieve of Eratosthenes | O(n log log n) | O(n log log n) | O(n log log n) | O(n) | |
|  | Euclidean GCD | O(log min(a,b)) | O(log min(a,b)) | O(log min(a,b)) | O(1) | |
| **Geometry** | Graham’s Scan | O(n log n) | O(n log n) | O(n log n) | O(n) | Convex Hull |
|  | Jarvis’s March | O(n·h) | O(n·h) | O(n·h) | O(n) | h = hull pts |
| **Greedy** | Activity Selection | O(n log n) | O(n log n) | O(n log n) | O(1) | |
|  | Huffman Coding | O(n log n) | O(n log n) | O(n log n) | O(n) | |
| **Divide & Conquer** | Binary Search | O(1) | O(log n) | O(log n) | O(1) | |
|  | Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | |
| **ML (Extra)** | Gradient Descent | O(nd) | O(nd) | O(nd) | O(d) | n = samples, d = features |
|  | k-Means | O(n·k·t·d) | O(n·k·t·d) | O(n·k·t·d) | O(k+d) | t = iterations |

---

**Note:** For competitive programming, remember the big ones:  
- **Searching:** O(log n) for binary  
- **Sorting:** O(n log n) for quick/merge  
- **Graphs:** O(V+E) for BFS/DFS  
- **DP:** Often O(n²) or O(n·W)  
- **Greedy:** O(n log n) with sorting  
