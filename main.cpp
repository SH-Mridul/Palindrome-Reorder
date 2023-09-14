#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int letters[26] = {0};
    string sen;
    cin>>sen;
    
    for(long long i = 0; i<sen.size(); i++){
        int index = sen[i] -'A';
        letters[index]++;
    }
    
    int check = 0;
    for(int i = 0; i < 26; i++) check += (letters[i] % 2);
        
    if(check>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
        
        
    char arr[sen.size()];
    long long l = 0, r = sen.size()-1;
    
    //for even letters
    for(int i = 0;i<26; i++){
        if(letters[i] != 0 && letters[i]%2 == 0){
            int diff = letters[i]/2;
            char letter = (char)65+i; 
            while(diff--){
                arr[l++] =  letter;
                arr[r--] =  letter;
            }
            
            letters[i] = 0;
        }
    }
    
    
    for(int i = 0;i<26; i++){
        if(letters[i] != 0 && letters[i]%2 == 1){
            int diff = letters[i];
            char letter = (char)65+i; 
            while(diff--){
                arr[l++] =  letter;
            }
            
            letters[i] = 0;
            break;
        }
    }
        

    
    
    for(int i = 0; i<sen.size(); i++){
        cout<<arr[i];
    }
    
    return 0;
}