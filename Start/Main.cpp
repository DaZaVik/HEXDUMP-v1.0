#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <windows.h>
int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	while (true) {
		std::ifstream file("C:\\Windows\\notepad.exe", std::ios::binary);

		if (!file.is_open()) {
			std::cout << "Программа не может быть выполнена из-за отстуствия файла\n";
			return 404;
		}
		std::vector<unsigned char> bytes(
			(std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>()
		);
		for (int i = 0; i < bytes.size(); i++) {
			if (i % 16 == 0) {
				std::cout << std::setw(8) << std::setfill('0') << i << "  ";
			}
			if ((i + 1) % 16 == 0) {
				std::cout << " |";
				for (int j = i - 15; j <= i; j++) {
					if (bytes[j] >= 32 && bytes[j] <= 126) { std::cout << (char)bytes[j]; }
					else { std::cout << "."; }
				}
				std::cout << "|\n";
			}
			std::cout << std::hex << std::setw(2) << (int)bytes[i] << " ";
		}
		std::cout << "\nРазмер → " << std::dec << bytes.size();
		return 0;

	}
	

}