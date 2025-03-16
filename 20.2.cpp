#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main() {
	int first_answer;
	int x, y;
	while (true) {
		std::cout << "You are ready? (1 - no (exit), 2 - yes )" << std::endl;
		std::cin >> first_answer;
		if (first_answer == 1) {
			std::cout << "Goodbye!";
			break;
		}
		else if (first_answer == 2) {
			std::ofstream picture("pic.txt", std::ios::app);

			std::cout << "Input size picture (x, y): ";
			std::cin >> x >> y;

			srand(time(0));
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++)
					picture << (rand() % 2);
				picture << std::endl;
			}
			std::cout << "Picture is ready!" << std::endl;
			picture.close();
		}
		else {
			std::cout << "!input error!" << std::endl;
		}
	}
}