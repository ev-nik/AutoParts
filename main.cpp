#include <iostream>
#include <vector>

#include "cars.h"
#include "Auto.h"
#include "Block.h"

enum Menu
{
    Exit,      // Выход
    AddACar,   // Добавить автомобиль
    DeleteCar, // Удалить  автомобиль
    СhooseCar  // Выбрать  автомобиль

};


// Вывести на печать вектор
void printAuto(std::vector<Auto>& cars)
{
    for(size_t i = 0; i < cars.size(); i++)
    {
        Auto a = cars[i];

        std::cout << a.id << " " <<  a.name << " " << '\n';
    }
}

// Вывести на печать выбранный автомобиль
void printTheAuto(std::vector<Auto>& cars, int num)
{
    for(size_t i = 0; i < cars.size(); i++)
    {
        Auto a = cars[i];

        if(a.id == num)
        {
            std::cout << a.id << " " << a.name << '\n';

            break;
        }
    }
}


// Удалить из вектора cars элемент у которого id совпадает с num
// Удаляется только первое совпадение
void deleteAuto(std::vector<Auto>& cars, int num)
{
    for(size_t i = 0; i < cars.size(); i++)
    {
        Auto a = cars[i];

        if(a.id == num)
        {   // Удалить элемент вектора
            cars.erase(cars.begin() + i);
            break;
        }
    }
}

// Вывести на печать существующие авто
void printAllAuto(std::map<int, std::string>& cars)
{
    for(std::map<int, std::string>::iterator it = cars.begin(); it != cars.end(); it++)
    {
        std::cout << it->first << " - " << it->second << '\n';
    }
}

// Добавить узел в авто
void addBlock(std::vector<Auto>& cars, std::string block)
{
    for(size_t i = 0; i < cars.size(); i++)
    {
      Auto a = cars[i];
    }
}

int main()
{
    std::vector<Auto> carsWithParts;


    bool t = true;

    while(t)
    {
        std::cout << "\n";
        std::cout << "#### MAIN MENU #### \n\n";
        std::cout << "[" << Exit       << "]" << "Exit         \n"
                  << "[" << AddACar    << "]" << "Add a car    \n"
                  << "[" << DeleteCar  << "]" << "Delete car   \n"
                  << "[" << СhooseCar << "]" << "Choose a car \n";


        int operation;
        std::cout << "-> ";
        std::cin >> operation;
        std::cout << "\n";

        switch(operation)
        {
            case Exit:
            {
                t = false;
                break;
            }

            case AddACar:
            {
                printAllAuto(cars);

                int id;

                std::cout << "\n";
                std::cout << "Select auto \n";
                std::cout << "-> ";
                std::cin  >> id;

                if(cars.count(id) == 1)
                {
                    std::cout << "Ok\n";

                    Auto car;
                    car.id = id;
                    car.name = cars[id];

                    carsWithParts.push_back(car);
                }
                else
                {
                    std::cout << "Error\n";
                }

                printAuto(carsWithParts);

                break;
            }

            case СhooseCar:
            {
                printAuto(carsWithParts);

                std::cout << "Select a car \n";
                std::cout << "-> ";

                int id;
                std::cin >> id;

                std::cout << '\n';

                //printTheAuto(carsWithParts, id);

                for(size_t i = 0; i < carsWithParts.size(); i++)
                {
                    Auto& a = carsWithParts[i];

                    if(a.id == id)
                    {
                        std::cout << a.name << '\n';

                        a.menu();

                        break;
                    }
                }

                break;
            }

            case DeleteCar:
            {
                printAuto(carsWithParts);

                std::cout << " Enter item number of delete \n";
                int num;
                std::cout << "-> ";
                std::cin >> num;

                deleteAuto(carsWithParts, num);

                printAuto(carsWithParts);

                break;
            }

            default:
            {
                std::cout << "Error \n";
                break;
            }
        }
    }
    return 0;
}
