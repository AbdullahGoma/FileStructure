#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;

class Engine
{
	char name[11], department[11], number[11];

	void read()
	{
		cout << "\nEnter name: ";
		cin >> name;

		cout << "Enter department: ";
		cin >> department;

		cout << "Enter phone number: ";
		cin >> number;
	}

	void pack(fstream& ofile) {
		read();

		ofile << name << '|' << department << '|' << number << '|';

		int len = strlen(name) + strlen(department) + strlen(number);
		while (len < 30)
		{
			ofile << '!';
			len++;
		}

		ofile << '\n';
	}

	void insert()
	{
		int n;
		cout << "Enter number of students: ";
		cin >> n;

		fstream ofile;
		ofile.open("database.txt", ios::out | ios::app);

		for (int i = 0, k; i < n; i++)
		{
			pack(ofile);
		}

		ofile.close();
	}

	void unpack(fstream& ifile) {
		ifile.getline(name, 11, '|');
		ifile.getline(department, 11, '|');
		ifile.getline(number, 11, '|');
		ifile.ignore(33, '\n');
	}

	void print()
	{
		fstream ifile;
		ifile.open("database.txt", ios::in);

		while (!ifile.eof())
		{
			unpack(ifile);
			if (!ifile.eof())
			{
				cout << "( " << name << ", ";
				cout << department << ", ";
				cout << number << " )\n";
			}
		}
	}

public:
	void run()
	{
		char choice;
		while (1)
		{
			cout << "1. Insert\n2. Print all\nAny other key to exit...\n\nYour choice: ";
			cin >> choice;

			cout << '\n';

			switch (choice)
			{
			case '1':
				insert();
				break;

			case '2':
				print();
				break;

			default:
				return;
			}

			cout << '\n';
		}
	}
};

int main(void)
{
	Engine engine;
	engine.run();

	return 0;
}