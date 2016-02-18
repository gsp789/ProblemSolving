#include <iostream>
#include <vector>

using namespace std;
inline int min(int a, int b)
{
	return a > b ? b : a;
}
int repeatedNumber(const vector<int> &A) {
	
    int length = A.size();
    vector<int> B(length - 1, 0);
	
    for(int i = 0; i < length; i++)
    {
        if(B[A[i] - 1] == 1)
            return A[i];
        else
            B[A[i] - 1] = 1;
    }

}

void main()
{
	int length = 0;
	cin >> length;
	
	vector<int> A(length, 0);
	
	for(int i = 0; i < length; i++)
	{
		cin >> A[i];
	}
	
	cout << repeatedNumber(A);
}

/* 

 1 <= A[i] <= (length - 1)

Testcase 1:
5
3 4 1 4 1

Output: 4 or 1(can display either of them)

Testcase 2:
7
3 1 4 2 5 6 5

Output: 5 
*/