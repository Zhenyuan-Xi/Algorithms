/*
There are a group of students. Some of them may know each other, while others don't. For example, A and B know each other, B and C know each other. 
But this may not imply that A and C know each other. Now you are given all pairs of students who know each other. 
Your task is to divide the students into two groups so that any two students in the same group don't know each other.
If this goal can be achieved, then arrange them into double rooms. 
Remember, only paris appearing in the previous given set can live in the same room, which means only known students can live in the same room.
Calculate the maximum number of pairs that can be arranged into these double rooms.

Input
For each data set:
The first line gives two integers, n and m(1<n<=200), indicating there are n students and m pairs of students who know each other. The next m lines give such pairs.
Proceed to the end of file.
Output
If these students cannot be divided into two groups, print "No". Otherwise, print the maximum number of pairs that can be arranged in those rooms.
 
Input
4 4
1 2
1 3
1 4
2 3
6 5
1 2
1 3
1 4
2 5
3 6
Output
No
3
*/
