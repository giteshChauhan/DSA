#include<iostream>
#include<string>
using namespace std;

// Function to check if strings are rotations of each other or not

bool isRotation(string s1,string s2){

    if(s1.length() != s2.length())
        return false;
    
    string temp=s1+s1;
    return(temp.find(s2) != string :: npos);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<isRotation(s1,s2)<<endl;
    return 0;
}