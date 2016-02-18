//Solution to find maximum sum sub array with some modification to kadane's algorithm

#include<iostream>
#include<vector>

using namespace std;

int MaximumSum(const vector<int> &A)
{
	int sum = numeric_limits<int>::min();
	int maxsum = numeric_limits<int>::min();

	int length = A.size();

	for(int i = 0; i < length; i++)
	{
		if(A[i] > 0 || A[i] > sum || sum + A[i] > 0)
		{
			if(sum > 0)
				sum += A[i];
			else
				sum = A[i];
		}
		else
			sum = numeric_limits<int>::min();

		if(sum > maxsum)
			maxsum = sum;

	}
	return maxsum;
}

void main()
{
	int length;
	cin >> length;

	vector<int> A(length, 0);
	for(int i = 0; i < length; i++)
		cin >> A[i];

	cout << MaximumSum(A);
}

/* Testcase 1:

6
-9 -8 -7 -80 -2 -6
Output : -2

Testcase 2:
1
-8

Output : -8

Testcase 3:

5
-9 -8 -4 6 -3

Output: 6

Testcase 4:

6
3 -2 4 1 -3 6
Output : 9

Testcase 5:
6
2 -5 3 1 -2 4

Output: 6

*/