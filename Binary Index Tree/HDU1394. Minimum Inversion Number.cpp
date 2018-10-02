/*
The inversion number of a given number sequence a1, a2, ..., an is the number of pairs (ai, aj) that satisfy i < j and ai > aj.
For a given sequence of numbers a1, a2, ..., an, if we move the first m >= 0 numbers to the end of the seqence, 
we will obtain another sequence. There are totally n such sequences as the following:
a1, a2, ..., an-1, an (where m = 0 - the initial seqence)
a2, a3, ..., an, a1 (where m = 1)
a3, a4, ..., an, a1, a2 (where m = 2)
...
an, a1, a2, ..., an-1 (where m = n-1)
You are asked to write a program to find the minimum inversion number out of the above sequences.

Input
The input consists of a number of test cases. Each case consists of two lines: the first line contains a positive integer n (n <= 5000); 
the next line contains a permutation of the n integers from 0 to n-1.
Output
For each case, output the minimum inversion number on a single line.
 
Input
10
1 3 6 9 0 8 5 7 4 2
Output
16
*/
