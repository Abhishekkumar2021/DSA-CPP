#include <bits/stdc++.h>
using namespace std;

/*
  A number N in base 10 has floor(log10(N))+1 digits, or in a more general way a number in base B has floor(logB(N))+ 1 digits.
  For example, N = 10 and B = 2 then we can express 10 in binary as 1010 --> 4 digits are there and if we go with formulae then digits = floor(log2(10) ) + 1 = 3 + 1


  let's understand the concept of binary exponentiation :
  let's take an example --> find 5^13 :
    so to this problem we can have a solution by simply Naive method i.e pow(5,13) = pow(5,12)*5 and againrepeating the same process till 1. but this solution is going to take O(N) time.
    But using the binary exponentiation method we can do it in O(log(N)) time. Let see how .....
    we can write 13 as 1101 now to find 5^13 we have to just multiply 3 terms as follows 5^13 = 5^8 * 5^4 * 5^1 . But to do this we must know the values of each term on right hand side which again follow the same process, so what is the benefit of using binomial exponentiation?
    we don't have to calculate each term again and again as because we can find pow(a,b) simply if we know the values of each term like a^1, a^2, a^4 ....a^floor(log2(N)). and we can see from it that the every next term is the square of the current term which is very helpful in the implementation. Let see How ?

*/

/*
    first solution is top-down approach:
               {  1 if b==0                      }
   pow(a,b) = {  pow(a,b/2)^2 if b==even        }
             {  a*pow(a,(b-1)/2)^2 if b==odd   }

    let see an example : pow(3,5) = ?
     ans = [3^5] = [3^2]*[3^2]*3 but as we don't know the value of [3^2] weagain recurse for this as [3^2] = [3^1]*[3^1] and then [3^1] = [1]*3 andin these few steps we have our answer.
*/

long long int powTopDown(long long int a, long long int b)
{
    if (b == 0)
        return 1;
    long long int ans = powTopDown(a, b / 2);
    if (b & 1)
        return a * ans * ans;
    else
        return ans * ans;
}

/*
    Next comes the bottom to top approach:
    let's take example of 5^10 as first we will express 10 as binary .... 10_dec = 1010_binary
    so what we are going to do is that we have to multiply only 5^(2^3)*5(2^1) as these corresponding bits are set to 1.
    so let's begin
*/

long long int powBottomUp(long long int a, long long b)
{
    long long int result = 1;
    while (b > 0)
    {
        int bit = b % 2;
        b >>= 1;
        if (bit == 1)
        {
            result = result * a;
        }
        a = a * a;
    }
    return result;
}

int main()
{
    long long int a, b;
    cin >> a >> b;
    clock_t timestamp = clock();
    cout << powTopDown(a, b) << "\n";
    timestamp = clock() - timestamp;
    cout << "Time taken = " << (float)timestamp / CLOCKS_PER_SEC << "\n";
    cout << powBottomUp(a, b) << "\n";
}