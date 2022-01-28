#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

// Function to find and print all duplicates along with thier counts in the string 

void printDuplicates(string str){

    unordered_map<char,int>mp;

    for(int i=0;i<str.length();i++)
        mp[str[i]]++;

    for(auto it: mp){
        if(it.second > 1)
            cout<<it.first<<" , count = "<<it.second<<endl;
    }
}

int main(){
    string str;
    cin>>str;
    printDuplicates(str);
    return 0;
}