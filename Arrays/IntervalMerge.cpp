/*
Problem:


Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

inline int min(int a, int b)
{
    return a < b ? a : b;    
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool doesIntersect(Interval e, Interval n)  // e - existing interval & n - newInterval
{
	if(min(e.end, n.end) <= max(e.start, n.start))
		return false;
	return true;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    int sz = intervals.size();
    if(newInterval.start > newInterval.end)
        swap(newInterval.start, newInterval.end);
    if(sz == 0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    else
    {
        vector<Interval> result;
        //New Interval comes at the beginning or at the end without overlap
        if(newInterval.end < intervals[0].start || newInterval.start > intervals[sz - 1].end)
        {
            if(newInterval.end < intervals[0].start)
                result.push_back(newInterval);
            for(int i = 0; i < sz; i++)
                result.push_back(intervals[i]);
            if(newInterval.start > intervals[sz - 1].end)
                result.push_back(newInterval);
            return result;
        }
        
        // If new interval lies between intervals
        
        for(int i = 0; i < sz; i++)
        {
            bool intersect = doesIntersect(intervals[i], newInterval);
            
            if(!intersect)
            {
                result.push_back(intervals[i]);
                if(i < sz - 1)
                    if(intervals[i].end < newInterval.start && newInterval.end < intervals[i + 1].start)
                        result.push_back(newInterval);
                continue;
            }
            
            int temp = i;
            while(i < sz && intersect)
            {
                i++;
                if(i == sz)
                    intersect = false;
                intersect = doesIntersect(intervals[i], newInterval);
            }
            i--; 
Interval insert(min(intervals[temp].start, newInterval.start), max(intervals[i].end, newInterval.end));
            result.push_back(insert);
        }
    }
}

void main()
{
	int l = 2;
	vector<Interval> intervals(l);
	intervals[0] = Interval(1, 2);
	intervals[1] = Interval(8, 10);
	Interval newInterval = Interval(3, 6);
	insert(intervals, newInterval);
	for(int i = 0; i < intervals.size(); i++)
	{
		cout << intervals[i].start << "  " << intervals[i].end << endl;
	}
}

/*
Testcase 1:
2             //no. of pairs
3 5 8 10  // two pairs
1 12   //newInterval

output: (1, 12)

Testcase 2:
2
1 2 8 10
3 6

Output: (1,2) (3,6) (8,10)

*/