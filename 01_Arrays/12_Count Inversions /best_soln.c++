// Question Link : https://www.codingninjas.com/studio/problems/count-inversions_615

// The solution that I am writing here is based upon the merge sort logic that striver explained in his video of this solution.

// TC : 0(nlogn)
// SC : 0(n)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void merge_sorted_arrays(int start_1, int end_1, int start_2, int end_2, long long *arr, long long &ans)
{
    int new_arr_1_size = end_1 - start_1 + 1;
    int new_arr_2_size = end_2 - start_2 + 1;

    int *new_arr_1 = new int[new_arr_1_size];
    int *new_arr_2 = new int[new_arr_2_size];

    for (int i = start_1; i <= end_1; i += 1)
    {
        new_arr_1[i - start_1] = arr[i];
    }

    for (int i = start_2; i <= end_2; i += 1)
    {
        new_arr_2[i - start_2] = arr[i];
    }

    int insert_index = start_1;
    int i = 0, j = 0;

    while (i < new_arr_1_size && j < new_arr_2_size)
    {
        if (new_arr_1[i] <= new_arr_2[j])
        {
            arr[insert_index] = new_arr_1[i];
            insert_index += 1;
            i += 1;
        }
        else
        {
            ans += (new_arr_1_size - i);
            arr[insert_index] = new_arr_2[j];
            insert_index += 1;
            j += 1;
        }
    }

    while (i < new_arr_1_size)
    {
        arr[insert_index] = new_arr_1[i];
        insert_index += 1;
        i += 1;
    }

    while (j < new_arr_2_size)
    {
        arr[insert_index] = new_arr_2[j];
        insert_index += 1;
        j += 1;
    }

    return;
}

void f(int start, int end, long long *arr, long long &ans)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    f(start, mid, arr, ans);
    f(mid + 1, end, arr, ans);
    merge_sorted_arrays(start, mid, mid + 1, end, arr, ans);
    return;
}

long long getInversions(long long *arr, int n)
{
    long long ans = 0ll;
    f(0, n - 1, arr, ans);
    return ans;
}