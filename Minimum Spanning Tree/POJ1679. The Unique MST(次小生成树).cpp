/*
Given a connected undirected graph, tell if its minimum spanning tree is unique. 
Definition 1 (Spanning Tree): Consider a connected, undirected graph G = (V, E). 
A spanning tree of G is a subgraph of G, say T = (V', E'), with the following properties: 
 1. V' = V. 
 2. T is connected and acyclic. 
Definition 2 (Minimum Spanning Tree): Consider an edge-weighted, connected, undirected graph G = (V, E). 
The minimum spanning tree T = (V, E') of G is the spanning tree that has the smallest total cost. 
The total cost of T means the sum of the weights on all the edges in E'. 
即求次小生成树,并比较两棵生成树是否相同

Input
The first line contains a single integer t (1 <= t <= 20), the number of test cases. Each case represents a graph. 
It begins with a line containing two integers n and m (1 <= n <= 100), the number of nodes and edges. 
Each of the following m lines contains a triple (xi, yi, wi), indicating that xi and yi are connected by an edge with weight = wi. 
For any two nodes, there is at most one edge connecting them.
Output
For each input, if the MST is unique, print the total cost of it, or otherwise print the string 'Not Unique!'.

Input
2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
Output
3
Not Unique!
*/
