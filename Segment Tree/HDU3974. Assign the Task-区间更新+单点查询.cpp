/*
There is a company that has N employees(numbered from 1 to N),every employee in the company has a immediate boss (except for the leader of whole company).
If you are the immediate boss of someone,that person is your subordinate, and all his subordinates are your subordinates as well. 
If you are nobody's boss, then you have no subordinates,the employee who has no immediate boss is the leader of whole company.
So it means the N employees form a tree.
The company usually assigns some tasks to some employees to finish.
When a task is assigned to someone,He/She will assigned it to all his/her subordinates.
In other words,the person and all his/her subordinates received a task in the same time. 
Furthermore,whenever a employee received a task,he/she will stop the current task(if he/she has) and start the new one.
Write a program that will help in figuring out some employee’s current task after the company assign some tasks to some employee.

Input
The first line contains a single positive integer T( T <= 10 ), indicates the number of test cases.
For each test case:
The first line contains an integer N (N ≤ 50,000) , which is the number of the employees.
The following N - 1 lines each contain two integers u and v, which means the employee v is the immediate boss of employee u(1<=u,v<=N).
The next line contains an integer M (M ≤ 50,000).
The following M lines each contain a message which is either
"C x" which means an inquiry for the current task of employee x
or
"T x y"which means the company assign task y to employee x. (1<=x<=N,0<=y<=10^9)
Output
For each test case, print the test case number (beginning with 1) in the first line and then for every inquiry, output the correspond answer per line.
 
Input
1 
5 
4 3 
3 2 
1 3 
5 2 
5 
C 3 
T 2 1
 C 3 
T 3 2 
C 3
Output
Case #1:
-1 
1 
2
*/
