// 20.3.cpp

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string fishUser;
	std::string fish;
	while (true) {
		std::cout << "name your fish: ";
		std::cin >> fishUser;

		std::ifstream river("river.txt", std::ios::app);
		std::ofstream basket("basket.txt", std::ios::app);

		if (river.is_open()) {
			std::cout << "file open";
			while (std::getline(river, fish))
			{
				if (fish == fishUser) {
					basket << fish << std::endl;
					std::cout << "Yes! The fish is caught!";
				}
			}
		}
		river.close();
		basket.close();
	}
}

