#include <iostream>
#include <Windows.h>
#include "Tree.h"


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	//строим дерево, которое будет словарем
	Trie* trie = new Trie;
	trie->insertKey("поле");
	trie->insertKey("полк");
	trie->insertKey("полоскать");
	trie->insertKey("плов");
	trie->insertKey("двигать");
	trie->insertKey("двигатель");
	trie->insertKey("движение");

	std::string userIn;
	bool run = true;
	while (run)
	{
		std::cout << "Введите префикс или \"выход\": ";
		std::cin >> userIn;
		if (userIn.compare("выход") == 0)
		{
			run = false;
			std::cout << "Программа закрыта пользователем";
			break;
		}
		if (trie->searchKey(userIn, true) == false)
		{
			std::cout << "Нет подходящих вариантов\n";
		}
		std::cout << std::endl;
	}
	delete trie;

	return 0;
}