/*
Network flow is a well-known difficult problem for ACMers. Given a graph, your task is to find out the maximum flow for the weighted directed graph.
Input
The first line of input contains an integer T, denoting the number of test cases.
For each test case, the first line contains two integers N and M, denoting the number of vertexes and edges in the graph. (2 <= N <= 15, 0 <= M <= 1000)
Next M lines, each line contains three integers X, Y and C, there is an edge from X to Y and the capacity of it is C. (1 <= X, Y <= N, 1 <= C <= 1000)
Output
For each test cases, you should output the maximum flow from source 1 to sink N.
 
Input
2
3 2
1 2 1
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
Case 1: 1
Case 2: 2
*/
