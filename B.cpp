#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
void reverseString(string &str){
    int n = str.length();
    for(int i = 0;i < n/2;i++){
        char temp = str[i];
        str[i] = str[n-(i+1)];
        str[n-(i+1)] = temp;


    }
}

int main()
{
    int n,max_name=10;
    cout << "Enter number of names (max 10)\n";
    cin >>n;
    string name[n];
    ifstream in;
    ofstream out;

  if (n<=max_name){
    in.open("input.text");
    for (int i = 0; i < n; i++){
        in>>name[i];
        }

    out.open("output.text");
    cout << "Names After reversed :" << endl;
    for (int j = 0; j < n; j++){
        out << reverseString(name[j]) << endl;
        cout << name[j] << endl;
        }
    }
    else
        cout << "Wrong number\n";
    return 0;
}