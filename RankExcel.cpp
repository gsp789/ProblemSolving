/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
*/

#include <iostream>
#include <string>
using namespace std;

long modpow(long a, long n)
{
    long res=1,y=a;
    while(n>0)
    {
        if(n&1)
            res=(res*y);
        y=(y*y);
        n/=2;
    }
    return res;
}

int titleToNumber(string A) {
    int num = 0;
    int prev = 0;
    int l = A.length();
    
    for(int i = 0; i < l; i++)
        num += modpow(26, i) + modpow(26, l - i - 1) * ((int)A[i] - 65);
        
    return num;
}

void main()
{
	string A;

	cout << "Enter the string(Only Capital Letters):";
	cin >> A;

	cout << titleToNumber(A);

}


/*
Test Case 1 :
A
1

Testcase 2:
Y
25

Testcase 3:
AZ
52

Testcase 4:
ABC
731

Testcase 5:
AAAB
18280
*/