#include <iostream>
#include <math.h>
using namespace std;
// calculates the number of places where both the string differs
int hammingDistance(string a, string b)
{
   int count = 0;
   for (int i = 0; i < a.size(); i++)
   {
      if (a[i] != b[i])
         count++;
   }
   return count;
}

int subgrids(int arr[][5], int r, int c)
{
   int sum = 0;
   for (int i = 0; i < r; i++)
   {
      for (int j = i; j < r; j++)
      {
         int count = 0;
         for (int k = 0; k < c; k++)
         {
            if (arr[i][k] == 1 && arr[j][k] == 1)
            {
               count++;
            }
         }
         sum += (((count - 1) * count) / 2);
      }
   }
   return sum;
}
int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int x = 17;
   cout << "Left shifted : " << (1 << 2) << endl; // The binary representation of 1 is going
   // to be shifted towards left as : 1 -> 100
   cout << "Right shifted : " << (1 >> 2) << endl; // In this case the shift is towards right
   // as : 1-> 00
   for (int i = 31; i >= 0; i--)
   {
      if (x & (1 << i))
         cout << "1";
      else
         cout << "0";
   } // This loop will print the binary representation of a number
   cout << endl;
   if ((x & (x - 1)) == 0)
      cout << x << " can be written as some power of 2\n";
   cout << "Leading zeroes = " << __builtin_clz(x) << endl;                // The number of zeroes at the begining(leading zeroes)
   cout << "Trailing zeroes = " << __builtin_ctz(x) << endl;               // The number of zeroes at the end(trailing zeroes)
   cout << "Number of 1's = " << __builtin_popcount(x) << endl;            // The number of ones in the number
   cout << "Parity of 1's(odd or even) = " << __builtin_parity(x) << endl; // parity(even or odd) of ones in the number
   // x = x|(1<<5);  //This will change the 5th index(index starts from zero and from right in case of bit programming) bit of x to 1
   // x = x&~(1<<2);   //This will change the 2nd index bit of x to 0
   // x = x^(1<<5); //this will invert the 5th index bit of x
   // x = x&(-x);//sets all the one bits to zero, except for the last 1
   // x = x|(x-1);  //inverts all the bits after the first 1 from right side

   //----------- Concept of representing set using bits-------------------
   // every subset of set {0,1,2,3 .........., n-1} can be represented as n bit integer whose each bit
   // tells whether that corresponding number is includes in the subset or not
   // For example, since int is a 32-bit type, an int number can represent any
   // subset of the set {0,1,2,...,31}. The bit representation of the set {1,3,4,8} is 00000000000000000000000100011010,
   // which corresponds to the number  282(binary to decimal)
   //-------------------------------- set implementation --------------------------

   int set = 0;
   set |= (1 << 1); // set the 1st index bit to 1
   set |= (1 << 3); // set the 3rd index bit to 1
   set |= (1 << 5); // set the 5th index bit to 1
   set |= (1 << 8); // set the 8th index bit to 1
   // or we can write in a single line as
   int newSet = (1 << 5) | (1 << 10) | (1 << 7) | (1 << 21);

   cout << "The set representation of {1,3,5,8} = " << set << endl;
   for (int i = 31; i >= 0; i--)
   {
      (set & (1 << i)) ? cout << "1" : cout << "0";
   }
   cout << endl;
   cout << "The set representation of {5,7,10,21} = " << newSet << endl;
   for (int i = 31; i >= 0; i--)
   {
      (newSet & (1 << i)) ? cout << "1" : cout << "0";
   }
   cout << endl;

   // printing all the elements that belongs to the set
   cout << "All the elments corresponding to " << set << endl;
   for (int i = 0; i < 32; i++)
   {
      if (set & (1 << i))
         cout << i << " ";
   }
   cout << endl;
   //--------------- set operation -----------------------
   int set_union_newSet = (set | newSet);
   cout << "The union of both the sets is " << endl;
   for (int i = 0; i < 32; i++)
   {
      if (set_union_newSet & (1 << i))
         cout << i << " ";
   }
   cout << endl;
   int set_intersection_newSet = (set & newSet);
   cout << "The intersection of both the sets is " << endl;
   for (int i = 0; i < 32; i++)
   {
      if (set_intersection_newSet & (1 << i))
         cout << i << " ";
   }
   cout << endl;
   int complementOfset = ~set;
   cout << "The complement of set is " << endl;
   for (int i = 0; i < 32; i++)
   {
      if (complementOfset & (1 << i))
         cout << i << " ";
   }
   cout << endl;

   int diffOfsetAndnewset = set & (~newSet);
   cout << "The difference of both the sets(set - newSet) is " << endl;
   for (int i = 0; i < 32; i++)
   {
      if (diffOfsetAndnewset & (1 << i))
         cout << i << " ";
   }
   cout << endl;

   //--------------- iterating through subsets -------------
   int n = 10;
   for (int k = 0; k < (1 << n); k++)
   { // loop will run 2^n times
      cout << "{ ";
      for (int i = 0; i < 32; i++)
      {
         if (k & (1 << i))
            cout << i << " ";
      }
      cout << "}" << endl;
   }
   // printing all the subsets having k elements
   int k = 4;
   cout << "Sets having " << k << " elements - " << endl;
   for (int b = 0; b < (1 << n); b++)
   {
      if (__builtin_popcount(b) == k)
      {
         cout << "{ ";
         for (int i = 0; i < 32; i++)
         {
            if (b & (1 << i))
               cout << i << " ";
         }
         cout << "}" << endl;
      }
   }
   // The following code go through the subset of set x
   int b = 0;
   do
   {
      cout << "{ ";
      for (int i = 0; i < 32; i++)
      {
         if (b & (1 << i))
            cout << i << " ";
      }
      cout << "}" << endl;
   } while (b = (b - x) & x);

   //---------------------- Bit optimizations ---------
   // concept of Hamming distances
   string A = "1010101010101010101010100110101001";
   string B = "0010011000101001001001100100101010";
   cout << "hammingDistance = " << hammingDistance(A, B) << endl;
   // we can implement the same thing using the bit optimisation
   int _A = 331;
   int _B = 160;
   cout << "hammingDistance = " << __builtin_popcount(_A ^ _B) << endl;
   //-------- Counting subgrids --------
   // Given an n× n grid whose each square is either black (1) or white (0), calculate the number
   // of subgrids whose all corners are black
   int grids[][5] = {{0, 1, 0, 0, 1}, {0, 1, 1, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 1, 0, 1}, {0, 0, 0, 0, 0}};
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         cout << grids[i][j] << " ";
      }
      cout << endl;
   }
   cout << "subgrids = " << subgrids(grids, 5, 5);
}