#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main() {
	string path;
	cin >> path;

	fstream file;
	file.open(path);
	if (!file.is_open(), fstream::out) {
		HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(window, 4);	// МНЕ НРАВИТСЯ ЭТА ШТУКА
		cout << "File is not open";
		return -1;
	}
	{ // ТУТ Я ПРОВЕРЯЮ РАСШИРЕНИЕ ФАЙЛА
		const string extension = "html";
		const string EXTENSION = "HTML";
		for (int i = path.find('.'); i < path.size(); i++) {
			if (extension.find(path[i]) == string::npos && EXTENSION.find(path[i]) == string::npos) {
				HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(window, 4);	//
				cout << "File is not open";
				return -1;
			}
		}
	}
	int closed = 0;
	int opened = 0;
	while (!file.eof())
	{
		char c;
		file >> c;
		switch (c) {
		case '<':
			opened++;
			break;
		case '>':
			closed++;
		}
	}
	file.close();
	if (closed != opened)
		cout << "\n\tFile is invalid\n";
	return 0;
}