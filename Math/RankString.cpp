/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba

The answer might not fit in an integer, so return your answer % 1000003

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Merge(vector<char> &S, int l, int h)
{
    int mid = (l + h) / 2;
    vector<char> L(mid - l + 1, 0);
    vector<char> R(h - mid, 0);
    int left = 0, right = 0;
    
    for(int i = 0; i <= mid- l; i++)
        L[i] = S[i + l];
        
    for(int i = 0; i < h - mid; i++)
        R[i] = S[i + mid + 1];
        
    int index = l;
    while(left <= mid - l && right < h - mid)
    {
        if(L[left] > R[right])
        {
            S[index] = R[right];
            right++;
        }
        else
        {
            S[index] = L[left];
            left++;
        }
        index++;
    }
    
    while(left <= mid - l)
    {
        S[index] = L[left];
        index++;
        left++;
    }
        
    while(right < h - mid)
    {
        S[index] = R[right];
        index++;
        right++;
    }
    
}

void MergeSort(vector<char> &S, int l, int h)
{
    if(l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(S, l, mid);
        MergeSort(S, mid + 1, h);
        Merge(S, l, h);
    }
}

int findRank(string A) {
    
    int l = A.length();
    if(l < 2)
        return 1;
	vector<char> sort(A.begin(), A.end());
    MergeSort(sort, 0, l - 1);
    
    vector<int> fact(l, 1);
    for(int i = 1; i < l; i++)
    {
        int f = fact[i-1] * i;
        fact[i] = f % 1000003;
    }
        
    int rank = 0;
    for(int i = 0; i < l - 1; i++)
    {
        for(int j = 0; j < sort.size(); j++)
        {
            if(A[i] == sort[j])
            {
                sort.erase(sort.begin() + j);
                break;
            }
            rank = (rank + fact[l - i - 1]) % 1000003;
        }
    }
    return rank + 1;
}

void main()
{
	string A;
	cout << " Enter the string to find its rank among its combinations:";
	cin >> A;

	cout << findRank(A);
}