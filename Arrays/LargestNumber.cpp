/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isGreater(string str1, string str2)
{
    /*
    int l1 = str1.length();
    int l2 = str2.length();
    int i1 = 0, i2 = 0;
    while(i1 < l1 || i2 < l2)
    {
        if((int)str1[i1] > (int)str2[i2])
            return true;
        else if((int)str2[i2] > (int)str1[i1])
            return false;
        else
        {
            i1++; i2++;
            if(i1 == l1 && i2 == l2)
                break;
            else if (i1 == l1)
                i1 = 0;
            else if (i2 == l2)
                i2 = 0;
                
        }
    }
    return true;
    */
    return str1 + str2 > str2 + str1;
}

void Merge(vector<string> &B, int l, int h)
{
    int left = 0, right = 0;
    int mid = (l + h) / 2;
    
    vector<string> L(mid - l + 1);
    vector<string> R(h - mid);
    
    for(int i = 0; i <= mid - l; i++)
        L[i] = B[i + l];
        
    for(int i = 0; i < h - mid; i++)
        R[i] = B[mid + 1 + i];
    
    int i = l;
    while(left <= mid - l && right < h - mid)
    {
        if(isGreater(L[left], R[right]))
            B[i++] = L[left++];
        else
            B[i++] = R[right++];
    }
    
    while(left <= mid - l)
        B[i++] = L[left++];
        
    while(right < h - mid)
        B[i++] = R[right++];
}

void MergeSort(vector<string> &B, int l, int h)
{
    if(l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(B, l, mid);
        MergeSort(B, mid + 1, h);
        Merge(B, l, h);
    }
}

string largestNumber(const vector<int> &A) {
    
    int l = A.size();
    vector<string> B(A.size());
    
    for(int i = 0; i < l; i++)
        B[i] = to_string(A[i]);
        
    MergeSort(B, 0, l - 1);
    string str = "";
    bool foundZero = true;
    for(int i = 0; i < l; i++)
    {
        if(B[i] != "0")
            foundZero = false;
        if(!foundZero)
            str.append(B[i]);
    }
     
    if(str == "") 
        return "0";
    else
        return str;
}

void main()
{
	cout << "***Form a largest number with elements in the array***" <<endl;
	int length;
	cout << "Enter the size of array:";
	cin >> length;

	vector<int> A(length);
	cout << "Enter elements in the array:";
	for(int i = 0; i < length; i++)
		cin >> A[i];

	cout << "Element formed:" << largestNumber(A);
}
