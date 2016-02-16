#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {

    vector< vector<int> > spiral (A, vector<int> (A,0));
    
    enum Direction { LeftToRight, TopToBottom, RightToLeft, BottomToTop };
    Direction d = LeftToRight;
    
    int row = 0, col = 0, counter = 1;
    
    while (counter <= (A * A))
    {
        spiral[row][col] = counter++;
        switch(d)
        {
            case LeftToRight:   col++;
                                if(col == A || spiral[row][col] != 0)
                                {
                                    d = TopToBottom;
                                    col--;
                                    row++;
                                }
                                break;
                                
            case TopToBottom:   row++;
                                if(row == A || spiral[row][col] != 0)
                                {
                                    d = RightToLeft;
                                    row--;
                                    col--;
                                }
                                break;
            
            case RightToLeft:   col--;
                                if(col < 0 || spiral[row][col] != 0)
                                {
                                    d = BottomToTop;
                                    col++;
                                    row--;
                                }
                                break;
            
            case BottomToTop:   row--;
                                if(row < 0 || spiral[row][col] != 0)
                                {
                                    d = LeftToRight;
                                    row++;
                                    col++;
                                }
                                break;
                            
            default : break;
            
        }
    }
    return spiral;
}

void main()
{
	int n;
	cout << "To build a n*n matrix, enter the value of n:";
	cin >> n;
	vector<vector<int>> spiral = generateMatrix(n);

	for (int index1 = 0; index1 < n; index1++)
	{
		for (int index2 = 0; index2 < n; index2++)
			cout << spiral[index1][index2] << "    ";
		cout << endl;
	}

}
