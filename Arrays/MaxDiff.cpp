//Find the maximum difference between elements in an array
// Note: Difference between two indices i and j is calculated as A[i] - A[j] where i < j

#include<iostream>
#include<vector>

using namespace std;

inline int findmax(int a, int b)
{
	return a > b ? a : b;
}

int MaxDifference(const vector<int> &A)
{
	int l = A.size();
	int max = A[0];
	int diff = 0;
	for(int i = 1; i < l; i++)
	{
		diff = findmax(diff, max - A[i]);
		max = findmax(max, A[i]);
	}
	return diff;
}

void main()
{
	int length;
	cout << "Enter length:";
	cin >> length;
	
	vector<int> A(length);
	cout<< "Enter the elements in the array:";
	for(int i = 0; i < length; i++)
		cin >> A[i];

	cout << MaxDifference(A);
}

/*
Testcase 1:
5
9 -2 4 12 0

output: 12

Testcase 2:
5
0 1 2 3 4

Output : 0

Testcase 3:
7
9 2 11 7 0

output : 11
*/

