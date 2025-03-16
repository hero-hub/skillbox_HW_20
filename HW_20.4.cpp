#include <iostream>
#include <fstream>
#include <cstdlib> // для rand()

int main()
{
    struct Banknote {
        int denomination;
        int count;
    };

    Banknote banknotes[6] = {
        {100, 200},
        {200, 200},
        {500, 200},
        {1000, 200},
        {2000, 200},
        {5000, 100}
    };

    int cashUser = 0;
    std::string command;
    do {
        int balance = 0;

        // Запись текущего состояния ATM в файл
        std::ofstream statusATM_out("statusATM.bin", std::ios::binary);
        if (statusATM_out.is_open()) {
            statusATM_out.write(reinterpret_cast<char*>(banknotes), sizeof(banknotes));
        }
        statusATM_out.close();

        // Чтение состояни
        std::ifstream statusATM_in("statusATM.bin", std::ios::binary);
        if (statusATM_in.is_open()) {
            statusATM_in.read(reinterpret_cast<char*>(banknotes), sizeof(banknotes));
        }
        statusATM_in.close();

        // Меню
        std::cout << "-----ATM-----" << std::endl;
        std::cout << "Current ATM state:" << std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << banknotes[i].denomination << " RUB: " << banknotes[i].count << " banknotes" << std::endl;
            balance += banknotes[i].count * banknotes[i].denomination;
        }
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "'+' - top up the ATM \n '-' - withdraw money \n 'exit' - shut down the ATM" << std::endl;
        std::cin >> command;

        if (command == "exit") break;

        //Пополнение инкассаторами 
        if (command == "+") {
            for (int i = 5; i >= 0; i--) {
            }
            if (balance < 1000) {
                banknotes[rand() % 6].count += 1000 - balance;
                std::cout << "The bills are deposited at the ATM." << std::endl;
            }
            else {
                std::cout << "ATM is already full." << std::endl;
            }
        }
        // Снятие денег
        else if (command == "-") {
            std::cout << "How much money do you want to withdraw?" << std::endl;
            std::cin >> cashUser;

            int remaining = cashUser;
            for (int i = 5; i >= 0; i--) {
                if (remaining >= banknotes[i].denomination) {
                    int needed = remaining / banknotes[i].denomination;
                    if (needed > banknotes[i].count) {
                        needed = banknotes[i].count;
                    }
                    remaining -= needed * banknotes[i].denomination;
                    banknotes[i].count -= needed;
                }
            }

            if (remaining == 0) {
                std::cout << "Money successfully withdrawn!" << std::endl;
            }
            else {
                std::cout << "Not enough bills to withdraw the requested amount." << std::endl;
            }
        }
    } while (true);

    return 0;
}