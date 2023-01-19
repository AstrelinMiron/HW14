#include <iostream>
#include <Windows.h>
#include "Tree.h"


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	//������ ������, ������� ����� ��������
	Trie* trie = new Trie;
	trie->insertKey("����");
	trie->insertKey("����");
	trie->insertKey("���������");
	trie->insertKey("����");
	trie->insertKey("�������");
	trie->insertKey("���������");
	trie->insertKey("��������");

	std::string userIn;
	bool run = true;
	while (run)
	{
		std::cout << "������� ������� ��� \"�����\": ";
		std::cin >> userIn;
		if (userIn.compare("�����") == 0)
		{
			run = false;
			std::cout << "��������� ������� �������������";
			break;
		}
		if (trie->searchKey(userIn, true) == false)
		{
			std::cout << "��� ���������� ���������\n";
		}
		std::cout << std::endl;
	}
	delete trie;

	return 0;
}