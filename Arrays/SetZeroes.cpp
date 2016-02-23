/*


Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1

On returning, the array A should be :

0 0 0
1 0 1
1 0 1

Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.

*/

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &A) {
    if(A.size() > 0)
    {
        int rows = A.size();
        int cols = A[0].size();
        vector<int> B(cols, 0);   
        for(int r = 0; r < rows; r++)
        {
            bool found = false;
            for(int c = 0; c < cols; c++)
            {
                if(A[r][c] == 0)
                {
                    B[c] = 1;
                    found = true;
                }
            }
            if(found)
            {
                for(int c = 0; c < cols; c++)
                    A[r][c] = 0;
            }
        }
                
        for(int c = 0; c < cols; c++)
        {
            if(B[c] == 1)
            {
                for(int r = 0; r < rows; r++)
                    A[r][c] = 0;
            }
        }
    }
}

void print(const vector<vector<int>> A)
{
	int rows = A.size();
	int cols = A[0].size();
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			cout << A[i][j] << "  ";
		cout << endl;
	}
}
void main()
{
	cout << "Enter the number of rows and columns in matrix:";
	int rows, cols;
	cin >> rows >> cols;

	vector<vector<int>> A(rows, vector<int>(cols));
	cout << "Enter the elements in the matrix(Row Wise):";
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			cin >> A[i][j];
	setZeroes(A);
	print(A);
}
