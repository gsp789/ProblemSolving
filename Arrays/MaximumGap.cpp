/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
*/

#include <iostream>
#include <vector>

using namespace std;

inline int findmax(int a, int b)
{
	return a > b ? a : b;
}

void Merge(vector<pair<int, int>> &S, int l, int h)
{
	int mid = (l + h) / 2;
	int left = 0;
	int right = 0;
	vector<pair<int, int>> L(mid - l + 1);
	vector<pair<int, int>> R(h - mid);

	for(int i = 0; i <= mid - l; i++)
		L[i] = S[i + l];

	for(int i = 0; i < h - mid; i++)
		R[i] = S[i + mid + 1];

	int i = l;
	while(left <= mid - l && right < h - mid)
	{
		if(L[left].first <= R[right].first)
			S[i++] = L[left++];
		else
			S[i++] = R[right++];
	}

	while(left <= mid - l)
		S[i++] = L[left++];

	while(right < h - mid)
		S[i++] = R[right++];
}

void MergeSort(vector<pair<int, int>> &S, int l, int h)
{
	if(l < h)
	{
		int mid = (l + h) / 2;
		MergeSort(S, l, mid);
		MergeSort(S, mid + 1, h);
		Merge(S, l, h);
	}
}

int maximumGap(const vector<int> &A) {

	int l = A.size();
	vector<pair<int, int>> S(l);
	for(int i = 0; i < l; i++)
		S[i] = make_pair(A[i], i);
	MergeSort(S, 0, l - 1);

	int max = S[l - 1].second;
	int diff = 0;
	for(int i = l - 2; i >= 0; i--)
	{
		diff = findmax(diff, max - S[i].second);
		max = findmax(max, S[i].second);
	}
	return diff;     
}

void main()
{
	int length;
	cout << "Enter the size of the array:";
	cin >> length;

	vector<int> A(length);
	cout << "Enter the elements in the array:";
	for(int i = 0; i < length; i++)
		cin >> A[i];

	cout << "Max Gap:" << maximumGap(A);
}