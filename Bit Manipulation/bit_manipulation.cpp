#include<bits/stdc++.h>

using namespace std;
void printSet(int n){
    for (int i = 0; i <= 31; i++){
        if (n & (1 << i))
        {
            cout << i << " ";
        }
    }
        
}
int main() {
    //set={0,1,2,3,4,5}
    // int set = 0;
    // for(int i=0; i<=3; i++){
    //     set = set | (1<<i);
    // }
    // cout<<set<<endl;
    //printing the set of values
    // for(int i=0; i<=31; i++){
    //     if(set&(1<<i)){
    //         cout<<i<<" ";
    //     }
    // }
    //intersection of two sets
    int set_A = 0;
    int set_B = 0;
    for (int i = 1; i <= 10; i++)
    {
        set_A = set_A | (1 << i);

    }
    for (int i = 4; i <= 13; i++)
    {
        set_B = set_B | (1 << i);
    }
    int set_intersection = set_A & set_B;
    // printSet(set_intersection);
    int set_union = set_B | set_A;
    // printSet(set_union);
    int complement_A = ~(set_A);
    // printSet( complement_A );
    int set_Difference = set_A&(~set_B);
    // printSet(set_Difference); //
    //all the subsets
    int count = 1;
    // for(int i=1; i<(1<<3); i++){
    //     printSet(i);
    //     cout<<"\n";
    //     // count++;
    // }
    cout<<__builtin_popcount(13)<<endl;
    return 0;
}

//set_A = {1,2,........10}
//set_B = {4,5.........13}

// {1} --> 1
// {2} --> 2

//{1,2,3};
//{1} --> 2
//{2} --> 4

