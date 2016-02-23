/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1

*/

#include <iostream>

using namespace std;

long modpow(int n, int pow)
{
    int r = 1, tn = n;   // r - result, tn - temp n
    while(pow > 0)
    {
        if(pow & 1)
            r *= tn;
        tn *= tn;
        pow /= 2;
    }
    return r;
}

int trailingZeroes(int A) {

    int r = 0;
    int n = 5;
    int i = 1;
    while(n <= A)
    {
        r += A / n;
        i++;
        n = modpow(5, i);
    }
    return r;
}

void main()
{
	int n;
	cout << "Enter a number to find trailing zeroes in its factorial:";
	cin >> n;

	cout << trailingZeroes(n);
}

