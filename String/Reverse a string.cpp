#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// Function to reverse a string 

string reverseString(string str){

    int i=0,j=str.length()-1;
    while(i < j){
        swap(str[i],str[j]);
        i++;
        j--;
    }

    return str;
}

int main(){
    string str;
    cin>>str;
    str=reverseString(str);
    cout<<str;
    return 0;
}