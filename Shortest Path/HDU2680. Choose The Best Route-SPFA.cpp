/*
One day , Kiki wants to visit one of her friends. As she is liable to carsickness , she wants to arrive at her friend’s home as soon as possible . 
Now give you a map of the city’s traffic route, and the stations which are near Kiki’s home so that she can take. You may suppose Kiki can change the bus at any station. 
Please find out the least time Kiki needs to spend. To make it easy, if the city have n bus stations ,the stations will been expressed as an integer 1,2,3…n.

Input
There are several test cases. 
Each case begins with three integers n, m and s,(n<1000,m<20000,1=<s<=n) n stands for the number of bus stations in this city and m stands for the number of directed ways between bus stations .
(Maybe there are several ways between two bus stations .) s stands for the bus station that near Kiki’s friend’s home.
Then follow m lines ,each line contains three integers p , q , t (0<t<=1000). means from station p to station q there is a way and it will costs t minutes .
Then a line with an integer w(0<w<n), means the number of stations Kiki can take at the beginning. Then follows w integers stands for these stations.
Output
The output contains one line for each data set : the least time Kiki needs to spend ,if it’s impossible to find such a route ,just output “-1”.

Input
5 8 5
1 2 2
1 5 3
1 3 4
2 4 7
2 5 6
2 3 5
3 5 1
4 5 1
2
2 3
4 3 4
1 2 3
1 3 4
2 3 2
1
1
Output
1
-1
*/

