/*
XXX is very interested in algorithm. After learning the Prim algorithm and Kruskal algorithm of minimum spanning tree, XXX finds that there might be multiple solutions. 
Given an undirected weighted graph with n (1<=n<=100) vertexes and m (0<=m<=1000) edges, he wants to know the number of minimum spanning trees in the graph.
即求最小生成树个数

Input
There are no more than 15 cases. The input ends by 0 0 0.
For each case, the first line begins with three integers --- the above mentioned n, m, and p. 
The meaning of p will be explained later. Each the following m lines contains three integers u, v, w (1<=w<=10), 
which describes that there is an edge weighted w between vertex u and vertex v( all vertex are numbered for 1 to n) . 
It is guaranteed that there are no multiple edges and no loops in the graph.
Output
For each test case, output a single integer in one line representing the number of different minimum spanning trees in the graph.
The answer may be quite large. You just need to calculate the remainder of the answer when divided by p (1<=p<=1000000000). 
p is above mentioned, appears in the first line of each test case.

Input
5 10 12
2 5 3
2 4 2
3 1 3
3 4 2
1 2 3
5 4 3
5 1 3
4 1 1
5 3 3
3 2 3
0 0 0
Output
4
*/

使用Kruskal算法+Kirchhoff矩阵,暂且不会。
