#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &A) {

    int rows = A.size();
    int columns = A[0].size();
    for(int i = 0; i < rows; i++)
        for(int j = i + 1; j < columns; j++)
        {
            swap(A[i][j], A[j][i]);
        }
        
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0, k = columns - 1; j < (rows + 1)/2; j++, k--)
        {
            swap(A[i][j], A[i][k]);
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
	int rows = 3;
	int columns = 3;
	vector<vector<int>> Matrix (rows, vector<int> (columns, 0));
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			cin >> Matrix[i][j];

	rotate(Matrix);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
}