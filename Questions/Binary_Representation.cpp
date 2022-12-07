/*
Write a c++ code to convert a decimal number to its binary representation.
Codechef: https://www.codechef.com/problems/BINREP
Codeforces: http://codeforces.com/problemset/problem/118/B
Hackerrank: https://www.hackerrank.com/challenges/binary-numbers
Leetcode: https://leetcode.com/problems/binary-number-with-alternating-bits/description/
Interviewbit: https://www.interviewbit.com/problems/binary-representation/
Atcoder: https://atcoder.jp/contests/abc127/tasks/abc127_b
GFG: https://practice.geeksforgeeks.org/problems/binary-representation/0
Hint: Use bitset
Bitset: https://www.geeksforgeeks.org/bitset-in-c-stl/
Can be solved using bitset, string, vector, stack, queue, deque, list, array, set, map, unordered_set, unordered_map, priority_queue, pair, tuple, forward_list, etc.
Article: https://www.geeksforgeeks.org/binary-representation-of-a-given-number/

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "";
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    cout << s << endl;
    return 0;
}

/*
Input:
10
Output:
1010

Dry Run:
n = 10
s = ""
n > 0, so loop runs
s = "0" + s = "0"
n = 10 / 2 = 5
n > 0, so loop runs
s = "1" + s = "10"
n = 5 / 2 = 2
n > 0, so loop runs
s = "0" + s = "010"
n = 2 / 2 = 1
n > 0, so loop runs
s = "1" + s = "1010"
n = 1 / 2 = 0
n <= 0, so loop breaks
s = "1010"
*/


/*
Time Complexity: O(log n)
Space Complexity: O(1)
Codechef: https://www.codechef.com/viewsolution/36000047
Codeforces: https://codeforces.com/contest/1352/submission/102000000
*/

