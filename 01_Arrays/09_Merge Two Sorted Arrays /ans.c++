// Question Link :
// https://www.codingninjas.com/studio/problems/1214628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Here main challenge is to merge two sorted arrays without using extra space

#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m,
                                 int n)
{
    // Write your code here.
    int insert_index = arr1.size() - 1;
    int i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[insert_index] = arr1[i];
            i -= 1;
            insert_index -= 1;
        }
        else
        {
            arr1[insert_index] = arr2[j];
            j -= 1;
            insert_index -= 1;
        }
    }

    while (i >= 0)
    {
        arr1[insert_index] = arr1[i];
        i -= 1;
        insert_index -= 1;
    }

    while (j >= 0)
    {
        arr1[insert_index] = arr2[j];
        j -= 1;
        insert_index -= 1;
    }

    return arr1;
}