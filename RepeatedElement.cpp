#include <iostream>
#include <vector>

using namespace std;
inline int min(int a, int b)
{
	return a > b ? b : a;
}
int repeatedNumber(const vector<int> &A) {
	
    int length = A.size();
    double root = sqrt((double)length - 1);
    int elements = ceil((length - 1)/root);
    vector<int> B(elements, 0);
    int repeat = - 1;
	
    for(int index = 0; index < length; index++)
    {
        for(int i = 0; i < elements; i++)
        {
            if(A[index] <= (root * (i + 1)) && A[index] > root * i )
            {
                B[i]++;
                if(B[i] > min(floor(root * (i + 1)), length - 1) - floor(root * i))
                    repeat = i;
                break;
            }
        }
    }

    for(int i = 0; i < elements; i++)
        B[i] = 0;
	
    for(int i = 0; i < length; i++)
    {
        if(A[i] > root * repeat && A[i] <= root * (repeat + 1))
        {
            if(B[A[i] - floor((root*repeat) + 1)] == 1)
                return A[i];
            else
                B[A[i] - floor((root*repeat) + 1)] = 1;
        }
    }
	
    return -1;
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