//Find the power of a number

#include <iostream>

using namespace std;

int pow(int n, int p)
{
	int d = 2147483647;
	long long r = 1, tn = n;
	while(p > 0)
	{
		if(p & 1)
			r = (r *tn) % d;
		tn = (tn * tn) % d;
		p /= 2;
	}
	if(r < 0)
		r = (r + d) % d;
	return r;
}

void main()
{
	int n, p;
	cout << "Enter the number:";
	cin >> n;

	cout << "Enter the number:";
	cin >> p;

	cout << pow(n, p);
}