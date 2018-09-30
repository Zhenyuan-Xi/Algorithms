/*
As is known to all, the blooming time and duration varies between different kinds of flowers. 
Now there is a garden planted full of flowers. The gardener wants to know how many flowers will bloom in the garden in a specific time. 
But there are too many flowers in the garden, so he wants you to help him.
 
Input
The first line contains a single integer t (1 <= t <= 10), the number of test cases.
For each case, the first line contains two integer N and M, where N (1 <= N <= 10^5) is the number of flowers, and M (1 <= M <= 10^5) is the query times. 
In the next N lines, each line contains two integer Si and Ti (1 <= Si <= Ti <= 10^9), means i-th flower will be blooming at time [Si, Ti].
In the next M lines, each line contains an integer Ti, means the time of i-th query.
Output
For each case, output the case number as shown and then print M lines. Each line contains an integer, meaning the number of blooming flowers.
Sample outputs are available for more details.
 
Input
2
1 1
5 10
4
2 3
1 4
4 8
1
4
6
Output
Case #1:
0
Case #2:
1
2
1
*/
