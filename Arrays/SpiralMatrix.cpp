#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > Solution::generateMatrix(int A) {

    vector< vector<int> > spiral (A, vector<int> (A,0));
    
    enum Direction { LeftToRight, TopToBottom, RightToLeft, BottomToTop };
    Direction d = LeftToRight;
    
    int currentrow = 0, currentcol = -1, counter = 1, loop = 1;
    
    while (counter <= (A * A))
    {
        switch(d)
	    {
	        case LeftToRight:   currentcol++;
	                            if(currentcol == A - loop)
	                                d = TopToBottom;
	                            break;
	                            
	        case TopToBottom:   currentrow++;
	                            if(currentrow == A - loop)
	                                d = RightToLeft;
	                            break;
	                            
	        case RightToLeft:   currentcol--;
	                            if(currentcol == loop - 1)
	                                d = BottomToTop;
	                            break;
	        case BottomToTop:   currentrow--;
	                            if(currentrow == loop)
	                            {
	                                loop++;
	                                d = LeftToRight;
	                            }
	        
	    }
	    spiral[currentrow][currentcol] = counter++;
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
