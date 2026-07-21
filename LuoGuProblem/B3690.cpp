#include <iostream>
using namespace std;
int main (){
    string s,t,target;
    while(cin>>s>>t){
        for(int i=1;i<min(s.length(),t.length());i++){
            if(s[i]==t[i]){
                cout<<s[i];
            }
            
        }
    }
}
