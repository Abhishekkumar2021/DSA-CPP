#include<bits/stdc++.h>
#include"Array_as_ADT_template.h"
#include "Stack_as_ADT_template.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  stackADT<int> stack;
  stack.createNewStack(5);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(8);
  cout<<stack.pop()<<"\n";
  cout << stack.pop() << "\n";
  cout << stack.pop() << "\n";
  cout << stack.pop() << "\n";
  cout << stack.pop() << "\n";
  cout << stack.pop() << "\n";
  cout << stack.pop() << "\n";
  cout << stack.pop() << "\n";
  return 0;
}