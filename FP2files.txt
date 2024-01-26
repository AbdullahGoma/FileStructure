#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;

class Engine
{
    char name[10], department[10], number[10];

public:
    void read()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter department: ";
        cin >> department;

        cout << "Enter phone number: ";
        cin >> number;
    }

    void insert()
    {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        fstream ofile1, ofile2;
        ofile1.open("database.txt", ios::out | ios::app);
        ofile2.open("index.txt", ios::out | ios::app);

        for (int i = 0, k; i < n; i++)
        {
            read();
            ofile1 << name << '|' << department << '|' << number << '|';
            ofile2 << name << '\n';

            k = strlen(name) + strlen(department) + strlen(number);
            while (k < 27)
            {
                ofile1 << '!';
                k++;
            }

            ofile1 << '\n';
        }

        ofile1.close();
        ofile2.close();
    }

    void print()
    {
        fstream ifile;
        ifile.open("database.txt", ios::in);

        while (!ifile.eof())
        {
            ifile.getline(name, 10, '|');
            ifile.getline(department, 10, '|');
            ifile.getline(number, 10, '|');
            ifile.ignore(30, '\n');

            if (!ifile.eof())
            {
                cout << "( " << name << ", ";
                cout << department << ", ";
                cout << number << " )\n";
            }
        }

        cout << '\n';
    }

    void search()
    {
        char key[10];
        cout << "Enter name: ";
        cin >> key;

        fstream ifile;
        ifile.open("index.txt", ios::in);

        int i;
        for (i = 0; !ifile.eof(); i++)
        {
            ifile.getline(name, 10, '\n');

            if (strcmp(key, name) == 0)
            {
                break;
            }
        }

        if (ifile.eof() and strcmp(key, name) != 0)
        {
            cout << "Name doesn't exist\n\n";
            ifile.close();
            return;
        }

        ifile.close();
        ifile.open("database.txt", ios::in);
        ifile.seekg(i * 32);

        ifile.getline(name, 10, '|');
        ifile.getline(department, 10, '|');
        ifile.getline(number, 10, '|');

        cout << "( " << name << ", ";
        cout << department << ", ";
        cout << number << " )\n\n";

        ifile.close();
    }

    void run()
    {
        char choice;
        while (1)
        {
            cout << "1. Insert\n2. Print all\n3. Search\nAny other key to exit...\n\nYour choice: ";
            cin >> choice;

            switch (choice)
            {
            case '1':
                insert();
                break;

            case '2':
                print();
                break;

            case '3':
                search();
                break;

            default:
                return;
            }
        }
    }
};

int main(void)
{
    Engine engine;
    engine.run();

    return 0;
}