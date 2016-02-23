/*
A robot is located at the top-left corner of an A x B grid.

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.
*/

#include <iostream>
using namespace std;

int mcn(int m, int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return m;
    int numerator = 1, denominator = 1;
    for(int i  = m, j = 1; j <= n; j++, i--)
    {
        numerator *= i;
        if(numerator % j == 0)
            numerator /= j;
        else
            denominator *= j;
    }
    return numerator/denominator;
}

inline int min(int a, int b)
{
    return a < b ? a : b;
}

int uniquePaths(int A, int B) {
    if(A == 1 || B == 1)
        return 1;
    int n = min(A - 1, B - 1);
    return mcn(A + B - 2, B - 1);
}

void main()
{
	int rows, cols;
	cout << "Enter the number of rows and columns:";
	cin >> rows >> cols;
	
	cout << uniquePaths(rows, cols);
}
