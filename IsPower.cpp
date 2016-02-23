// Given a positive integer which fits in a 32 bit signed integer, 
// find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

#include <iostream>

using namespace std;

long modpow(long num, long p)
{
    long r = 1, t = num;
    while(p > 0)
    {
        if(p & 1)
            r *= t;
        t *= t;
        p /= 2;
    }
    return r;
}

bool isIPower(int A, int p)
{
    for(int i = 2; ; i++)
    {
        long power = modpow(p, i);
        if(A < power)
            break;
        if(A == power)
            return true;
    }
    return false;
}

int sqrt(int A)
{
    int left = 1, right = A;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int sq = A / mid;
        if(sq > mid)
            left = mid + 1;
        else if(sq < mid)
            right = mid - 1;
        else
            return mid;
    }
    return right;
}

bool isPower(int A) {
    if(A == 1 || A == 0)
        return true;
    int l = sqrt(A); //limit
    bool isPow = false;
    for(int i = 2; i <= l; i++)
    {
        if(A % i == 0)
        {
            if(isIPower(A, i) || isIPower(A, A/i) || i == A / i)
                return true;
        }
    }
    return false;
}

void main()
{
	int n;
	cout << "Enter a number:";
	cin >> n;

	cout << isPower(n);
}

/*Testcase 1:
8

output : 1

Testcase 2:
0
output : 1

Testcase 3:
14
output: 0

Testcase 4:
16
output : 1

Testcase 5:
27
output: 1

Testcase 6:
50
output : 0
*/
