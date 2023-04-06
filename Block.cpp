#include <iostream>
#include <iostream>
#include <vector>

#include "Part.h"
#include "Block.h"
#include "Auto.h"

// Меню блока / раздела (что можно делать внутри блока / раздела)
enum MenuBlock
{
    Back,       // Назад
    AddPart,    // Добавить деталь
    DeletePart, // Удалить деталь
    PrintParts  //

};


// Добавить деталь
void Block::addPart(std::string name)
{
    Part part;
    part.name = name;
    blockParts.push_back(part);
}


// Вывести на печать все внесенные детали
void Block::printParts()
{
    for(size_t i = 0; i < blockParts.size(); i++)
    {
        Part a = blockParts[i];
        std::cout << a.name << '\n';

    }
}

void Block::deletePart(std::string namePart)
{
    for(size_t i = 0; i < blockParts.size(); i++)
    {
        Part a = blockParts[i];
        if(a.name == namePart)
        {
            blockParts.erase(blockParts.begin() + i);
            break;
        }
    }
}

void Block::menu()
{
    bool t = true;
    while(t)
    {

        std::cout << "\n";
        std::cout << "#### BLOCK " << name << "####\n\n";
        std::cout << "[" << Back       << "]" << " Back \n"
                  << "[" << AddPart    << "]" << " Add part \n"
                  << "[" << DeletePart << "]" << " Delete part \n"
                  << "[" << PrintParts << "]" << " Print parts \n";

        std::string tmp;
        std::cout << "-> ";
        std::cin >> tmp;
        int operation;

        // Преобразование строки в число
        // Функция stoi() выбрасывает исключение
        // когда невозможно преобразовать строку в число
        // Например: stoi("ABC") - будет исключение
        // так как ввод производится с консоли,
        // то ввести пользователь может не только число
        try
        {
            operation = std::stoi(tmp);
        }
        catch(std::invalid_argument)
        {
            std::cout << "OOOOPs\n";
            continue;
        }

        switch(operation)
        {
            case Back:
            {
                t = false;
                break;
            }
            case AddPart:
            {
                std::string namePart;
                std::cout << "Enter name part \n";
                std::cout << "-> ";
                std::cin >> namePart;

                addPart(namePart);
                printParts();

                break;
            }

            case DeletePart:
            {
                std::cout << "Enter a part to delete \n";
                std::cout << "\n";

                std::string namePart;
                std::cout << "-> ";
                std::cin >> namePart;

                deletePart(namePart);
                printParts();

                break;
            }

            case PrintParts:
            {
                printParts();
                break;
            }

            default:
            {
                std::cout << "Error \n";
                break;
            }
        }
    }
}
