// #include<iostream>
// #include<fstream>
// #include<string.h>
// using namespace std;
// int main(int argc, char* argv[]) {
//     int k = atoi(argv[1]);
//     cout<<k;
//     fstream newFile;
//     newFile.open(argv[2]);
//     if (!newFile.is_open())
//         cout << "File not found :(";
//     else {
//         int lines = 0;
//         while(newFile){
//             char t = newFile.get();
//             if(t == '\n')
//             lines++;
//         }
//         int temp = 0;
//         newFile.seekg(0,ios::beg);
//         cout << lines;
//         char t = newFile.get();
//         cout<<t;
//         newFile.close();
//     }
// }

#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
using namespace std;
void print_fn(int k, string s)
{
    int count = 0;
    stack<string> st;
    string x;
    ifstream fin;
    int length =0;
    fin.open(s, ios::in);
    {
        while (!fin.eof())
        {
            getline(fin, x);
            length++;  
        }
    }
    fin.close();
    fin.open(s, ios::in);
    {
        while (!fin.eof())
        {
            getline(fin, x);
            st.push(x);
            count++;
            if (count > length-k)
            {
                cout << st.top()<<endl;
            }
        }
    }
}
int main(int argc, char* argv[]) {
    int k = atoi(argv[1]);
    print_fn(k, argv[2]);
    return 0;
}