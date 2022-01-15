#include <bits/stdc++.h>
using namespace std;
// custom class to help in returning three things.
class ans
{
public:
    int left_index;
    int right_index;
    int sum;
    ans(int l, int r, int sum)
    {
        left_index = l;
        right_index = r;
        this->sum = sum;
    }
    friend ostream &operator<<(ostream &out, const ans &bin)
    {
        out << "left_index: " << bin.left_index << ", right_index: " << bin.right_index << ", sum: " << bin.sum << "\n";
        return out;
    }
};
ans max_crossing_sub_array(int A[], int low, int high)
{
    int mid = (high + low) / 2;
    // calculating the max left sum and the index of the left element of the maximum subarray.
    int left_sum = 0; // act as - (infinity)
    int left_index = mid;
    int sum = 0;
    for (int i = mid; i >= 0; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_index = i;
            left_sum = sum;
        }
    }
    // calculating the max right sum and the index of the right element of the maximum subarray.
    int right_sum = 0; // act as - (infinity)
    int right_index = mid;
    sum = 0;
    for (int i = mid + 1; i < high; i++)
    {
        sum += A[i];
        if (sum > right_sum)
        {
            right_index = i;
            right_sum = sum;
        }
    }
    return ans(left_index, right_index, left_sum + right_sum);
}
/*
The recurrence relationship for this divide and conquer problem can be obtained as-
let T(n) be the time complexity of the problem. Then,
a) for base case i.e n = 1, we have to do theta(1) of work
b) for any n>1 we can compute the complexity as below-
    T(n) = theta(1) + T(n/2) + T(n/2) + theta(n);
         = 2T(n/2) + theta(n)
and for this type of recurrence relation we get the complexity as O(nlogn).
*/
ans max_sum_subarray(int A[], int low, int high)
{
    if (high == low)
    {
        return ans(low, high, A[low]);
    }
    int mid = (low + high) / 2;
    // let's first find the max subarray in the left,right and cross way.
    ans answer_left = max_sum_subarray(A, low, mid);
    ans answer_right = max_sum_subarray(A, mid + 1, high);
    ans answer_cross = max_crossing_sub_array(A, low, high);
    if ((answer_left.sum >= answer_right.sum) && (answer_left.sum >= answer_cross.sum))
        return answer_left;
    if ((answer_right.sum >= answer_left.sum) && (answer_right.sum >= answer_cross.sum))
        return answer_right;
    return answer_cross;
}

ans max_sum_subarray_brute_force(int A[], int low, int high)
{
    int best_sum = 0;
    int left_index = low;
    int right_index = low;
    for (int i = low; i <= high; ++i)
    {
        int sum = 0;
        for (int j = i; j <= high; ++j)
        {
            sum += A[j];
            if (sum > best_sum)
            {
                left_index = i;
                right_index = j;
                best_sum = sum;
            }
        }
    }
    return ans(left_index, right_index, best_sum);
} // Time complexity is O(n^2)
ans max_sum_subarray_linear(int A[], int low, int high) // also known as kadane's algorithm
{
    int best_sum = 0;
    int left_index = low;
    int right_index = low;
    int currLow = 0;
    int currHigh = 0;
    int sum = 0;
    for (int i = low; i <= high; ++i)
    {
        currHigh = i;
        if (sum > 0)
        {
            sum += A[i];
        }
        else
        {
            sum = A[i];
            currLow = i;
        }
        if (sum > best_sum)
        {
            left_index = currLow;
            right_index = currHigh;
            best_sum = sum;
        }
    }
    return ans(left_index, right_index, best_sum);
}

int main()
{
    int arr[] = {-1, -2, 20, -4, 5, -6};
    ans answer = max_crossing_sub_array(arr, 0, 5);
    cout << answer;
    ans overall = max_sum_subarray_linear(arr, 0, 5);
    cout << overall;
    return 0;
}