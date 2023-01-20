#include <iostream>
#include <Windows.h>
#include "Tree.h"


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	//строим дерево, которое будет словарем
	Trie* trie = new Trie;
	trie->insertKey("doom");
	trie->insertKey("dove");
	trie->insertKey("diving");
	trie->insertKey("divide");
	trie->insertKey("moon");
	trie->insertKey("move");
	trie->insertKey("dim");

	std::string userIn;
	bool run = true;
	while (run)
	{
		std::cout << "Enter the prefix \"exit\": ";
		std::cin >> userIn;
		if (userIn.compare("exit") == 0)
		{
			run = false;
			std::cout << "Programm has been closed";
			break;
		}
		if (trie->searchKey(userIn, true) == false)
		{
			std::cout << "There is no match\n";
		}
		std::cout << std::endl;
	}
	delete trie;

	return 0;
}