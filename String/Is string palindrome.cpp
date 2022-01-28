#include<iostream>
#include<string>
using namespace std;

// Function to check whether string is palindrome or not ( returns 1 is yes or 0 if not )

bool isPalindrome(string S){

    int i=0,j=S.length()-1;
    while(i < j){
        if(S[i] != S[j])
            return 0;
        i++;
        j--;
    }

    return 1;
}

int main(){
    string S;
    cin>>S;
    cout<<isPalindrome(S)<<endl;
    return 0;
}