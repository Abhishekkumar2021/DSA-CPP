#include<bits/stdc++.h>
using namespace std;
vector<string> deserialize(string s) {
    vector<string> ans;
    string temp = "";
    string num = "";
    int n = s.size(); 
    for(int i=0; i<n; i++){
        if(s[i]<='9' && s[i]>='0'){
            num+=s[i];
        }
        if(s[i]=='~'){
            cout<<"num = "<<num<<"\n";
            
            int l = num.size();
            int x = 0;
            if(num!="")
            x = stoi(num);
            num = "";
            for(int j=i-(x+l); j<=i-(l+1); j++){
                temp+=s[j];
            }
            cout<<"temp = "<<temp<<"\n";
            ans.push_back(temp);
            temp="";
        }
    }
}

int main(){
    deserialize("mxxxzclaql10~omttepvukq10~sckhqgagqt10~miaufqvumh10~jndrqnllah10~wqlithzmfi10~oczafaqcrz10~lnubllvcsq10~rzngzhllmw10~ntpvbeyxnk10~");
}