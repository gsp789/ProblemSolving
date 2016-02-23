/*
Reverse digits of an integer.

Example1:

x = 123,

return 321

Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/

#include <iostream>

using namespace std;

long modpow(long num, long p)
{
    long res = 1, t = num;
    while(p > 0)
    {
        if(p & 1)
            res *= t;
        t *= t;
        p /= 2;
    }
    return res;
}

int reverse(int A) {
    int limit = modpow(2, 31);
    int ulimit = limit - 1;
    int slimit = limit - (limit * 2);
    int num = A;
    long res = 0;
    while(num != 0)
    {
        res = res * 10 + (num % 10);
        num = num/10;
    }
    if(res < slimit || res > ulimit)
        return 0;
    return res;
}
void main()
{
	int n;
	cout << "Enter an integer:";
	cin >> n;

	cout << reverse(n);
}


/*
Testcase 1:
-1234567891

Output: -1987654321

Testcase 2:
-1146467285

output: 0

Testcase 3:
-1110968012

output:
-2108690111

Testcase 4:
-1170064042

output : 0
*/