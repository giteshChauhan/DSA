#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string removeDuplicates(string str){

    string newStr;
    unordered_set<char>s;

    for(int i=0;i<str.length();i++){
        if(s.find(str[i]) == s.end())
            newStr+=str[i];
        s.insert(str[i]);
    }

    return newStr;
}

int main(){
    string str;
    cin>>str;
    cout<<removeDuplicates(str)<<endl;
    return 0;
}