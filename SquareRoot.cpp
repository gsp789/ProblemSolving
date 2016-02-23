//Find the Squareroot of a number
#include <iostream>

using namespace std;

int sqrt(int x)
{
    if(x == 0)
        return 0;
    int left = 1, right = x;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int sq = x / mid;
        if(sq > mid)
            left = mid + 1;
        else if(sq < mid)
            right = mid - 1;
        else
            return mid;
    }
    return right;
}

void main()
{
	int n;
	cout << "Enter the number:";
	cin >> n;

	cout << sqrt(n);
}