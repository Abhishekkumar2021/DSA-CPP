#include<bits/stdc++.h>
using namespace std;
int main() {
 unordered_map<string,int> map;
 //insertion
 pair<string,int> p("hello",1);
 map.insert(p);
 map["bye"] = 2;
 //find or access
 cout<<map["hello"]<<endl;
 cout<<map["abc"]<<endl;  //there is already no abc is present as key so what this statementwill do is that it will create new one and give thatdefault value as 0
 cout<<map.at("abc")<<endl;  //if there is no key "abc" then this function will not create new key rather it will show error that there is no key "abc"


 //to check whether a key is present or not
 if(map.count("abc")>0){   //count is a function that returns the number of times a key is present (in map a key can present at max one time ). It returns 0 or 1.
   cout<<map["abc"]<<endl;  
 }

 //size of map 
 cout<<"Size of map: "<<map.size()<<endl;

 //erasing the elemnt from the map

 map.erase("abc"); //
 cout<<"Size of map: "<<map.size()<<endl;
  return 0;
}