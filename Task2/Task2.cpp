#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <algorithm>

class Address
{
public:
    Address(std::string city, std::string street, int house, int flat) : _city{ city }, _street{ street }, _house{ house }, _flat{ flat } {};

    const std::string getCity() const
    {
        return _city;
    }

    const std::string getStreet() const
    {
        return _street;
    }

    const int getHouse() const
    {
        return _house;
    }

    const int getFlat() const
    {
        return _flat;
    }

private:
    std::string _city;
    std::string _street;
    int _house;
    int _flat;
};

bool compareCity(const Address& one, const Address& two);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string fileNameInput{ "in.txt" };
    std::ifstream fileInput{ fileNameInput };
    if (fileInput.is_open())
    {
        int count{};
        fileInput >> count;

        std::vector<Address> address;
        while (!fileInput.eof())
        {
            std::string city;
            std::string street;
            int house;
            int flat;

            fileInput >> city;
            fileInput >> street;
            fileInput >> house;
            fileInput >> flat;

            Address temp(city, street, house, flat);
            address.push_back(temp);
        }
        fileInput.close();

        std::sort(address.begin(), address.end(), compareCity);

        std::string fileNameOutput{ "out.txt" };
        std::ofstream fileOutput{ fileNameOutput };
        if (fileOutput.is_open())
        {
            fileOutput << count << std::endl;
            for (Address element : address)
            {
                fileOutput << element.getCity() << ", " << element.getStreet() << ", " << element.getHouse() << ", " << element.getFlat() << std::endl;
            }
            fileOutput.close();
        }
        else
        {
            std::cout << "Файл для записи не открыт!";
        }

    }
    else
    {
        std::cout << "Файл для считывания не открыт!";
    }
}

bool compareCity(const Address& one, const Address& two)
{
    return one.getCity() < two.getCity();
}