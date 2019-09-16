#include <iostream>
#include <string>

#include "BST.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{

	BST<int> tree;
	

	cout << "Commands: " << endl;
	cout << "i or I followed by int will insert data" << endl;
	cout << "f or F followed by int will try to find data" << endl;
	cout << "c or C followed by int will indicate if tree contains data" << endl;
	cout << "r or R followed by int will remove data" << endl;
	cout << "d or D will display tree" << endl;
	cout << "q or Q will quit" << endl;

	string command;
	int data;
	cin >> command;
	while( !cin.fail() && ( command != "q" && command != "Q" ) )
	{
		cout << "Command: " << command;
		if ( command == "i" || command == "I" )
		{
			cin >> data;
			cout << " Data: " << data << endl;

			if (tree.insert(data) )
				cout << "inserted" << endl;
			else
				cout << "not inserted" << endl;
		}
		else if ( command == "f" || command == "F" )
		{
			cin >> data;
			cout << " Data: " << data << endl;
			int found = tree.find(data);
			cout << "found: " << found << endl;
		}
		else if ( command == "c" || command == "C" )
		{
			cin >> data;
			cout << " Data: " << data << endl;
			bool found = tree.contains(data);
			if ( found )
				cout << "contains: " << data<< endl;
			else
				cout << "does not contain: " << data<< endl;
		}
		else if ( command == "r" || command == "R" )
		{
			cin >> data;
			cout << " Data: " << data << endl;
			int found = tree.remove(data);
			cout << "removed: " << found << endl;
		}
		else if ( command == "d" || command == "D" )
		{
			cout << endl;
			cout << tree;
		}
		else
		{
			cout << "Commands: " << endl;
			cout << "i or I followed by int will insert data" << endl;
			cout << "f or F followed by int will try to find data" << endl;
			cout << "c or C followed by int will indicate if tree contains data" << endl;
			cout << "r or R followed by int will remove data" << endl;
			cout << "d or D will display tree" << endl;
			cout << "q or Q will quit" << endl;
		}
		cin >> command;
	}

}
