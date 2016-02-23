//Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space i.e., A[i] = A[A[i]]
// Note: Elements in the array must be b/w 1 to (n - 1) where n is the number of elements
#include <iostream>
#include <vector>

using namespace std;

void arrange(vector<int> &A) {
    
    int l = A.size();           // length of array
    for(int i = 0; i < l; i++)
    {
        A[i] += (A[A[i]] % l) * l;
    }
    
    for(int i = 0; i < l; i++)
    {
        A[i] /= l;
    }
}

void print(vector<int> A)
{
	int sz = A.size();

	for(int i = 0; i < sz; i++)
	cout << A[i] << "  ";
}

void main()
{
	int sz;
	cout << "Enter the size of array: ";
	cin >> sz;

	vector<int> A(sz);
	cout << "Enter the elements in the array:";
	for(int i = 0; i < sz; i++)
		cin >> A[i];

	arrange(A);
	print(A);
}