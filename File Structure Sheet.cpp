#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class std_file
{
private:
    char name[10][20];
    char input[20],output[20],str[20];
public:
    void std_io();
    void file_io();
};

void std_file::std_io()
{
    int n,i;
    cout<<"enter the number of names to read "<<endl;
    cin>>n;
    cout<<"enter the names"<<endl;
    for(i=0; i<n; i++)
        gets(name[i]);

    cout<<"the reversed names are"<<endl;
    for(i=0; i<n; i++)
        cout<<strrev(name[i])<<endl;
}

void std_file::file_io()
{
    fstream ifile,ofile;
    cout<<"enter the filename which contain list of names"<<endl;
    cin>>input;
    ifile.open(input,ios::in);
    if(!ifile) {
        cout<<"file doesnot exist";
        exit(0);
        getch();
    }
    cout<<"enter the filename to store names in reverse order"<<endl;
    cin>>output;
    ofile.open(output,ios::out);
    while(!ifile.eof()) {
        ifile.getline(str,20);

        ofile<<strrev(str)<<endl; //to reverse string characters
    }
}
int main()
{
    int num;
    std_file s;
    for(;;) {
        cout<<"1:file i/o\n2:standard i/o\nany other to exit\n";
        cin>>num;
        switch(num) {
        case 1:
            s.file_io();
            break;
        case 2:
            s.std_io();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
