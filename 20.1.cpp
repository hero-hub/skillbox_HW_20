#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string input;    

    std::string name;
    std::string lastName;
    std::string date;
    int sum;

    while(1)
    {
        bool flag = false;
        std::cout << "Input your name, lastname, date (NN.MM.YYYY) and sum: ";
        std::cin >> name >> lastName >> date >> sum;

        for (int i = 0; i < size(name); i++){
            char c = name[i];
            if (c <= 'z' && c >= 'a' || c <= 'A' && c >= 'Z'){
                continue;
            } 
            else
            {
                flag = true;
                std::cout << "Invalid name" << std::endl;
                break;
            }
        }
        if (flag) continue;

        for (int i = 0; i < size(lastName); i++){
            char c = lastName[i];
            if (c <= 'z' && c >= 'a' || c <= 'A' && c >= 'Z'){
                continue;
            } 
            else
            {
                flag = true;
                std::cout << "Invalid lastname" << std::endl;
                break;
            }
        }
        if (flag) continue;

        if(date[2] != '.' || date[5] != '.'){
            std::cout << "Invalid format date! NN.MM.YYYY" << std::endl;
            continue;
        }
        else
        {
            int num = std::stoi(date.substr(0,2));
            if (num > 31 || num < 1)
            {
                std::cout << "Invalid num" << std::endl;
                continue;
            }

            int mounth = std::stoi(date.substr(3,2));
            if (mounth > 12 || mounth < 1)
            {
                std::cout << "Invalid mounth" << std::endl;
                continue;
            } 

            int year = std::stoi(date.substr(6,4));
            if (year > 2025 || year < 1)
            {
                std::cout << "Invalid year" << std::endl;
                continue;
            }
        }

        if (sum < 0)
        {
            std::cout << "Invalid sum" << std::endl;
            continue;
        }
        
        std::ofstream file("uchet.txt", std::ios::app);

        file << "Name: " << name << std::endl;
        file << "Last Name: " << lastName << std::endl;
        file << "Data: " << date << std::endl;
        file << "Sum: " << sum << std::endl;
        
        file.close();

        std::cout << "Your information has been recorded in the 'uchet.txt'" << std::endl;
    }

}