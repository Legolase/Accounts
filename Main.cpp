#include <iostream>
#include <vector>
#include "stdio.h"
#include "Syst.h"

using namespace std;

int main() {
	system("chcp 1251 >nul");
	string command;
	while (true) {
		cout << "> ";
		cin >> command;
		if (command == "выход")
			break;
		else if (command == "регист")
			regist();
		else if (command == "вход")
			checkin();
	}
}
