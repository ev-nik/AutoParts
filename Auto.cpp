#include <iostream>
#include <vector>

#include "Auto.h"
#include "Block.h"
#include "Part.h"

// Меню автомобиля(что можно делать внутри автомобиля)
enum MenuBlocks
{
    BackMainMenu, // Вернуться в главное меню
    Add_Block,    // Добавить блок
    DeleteBlock,  // Удалить блок
    SelectBlock,  // Выбрать блок
    PrintBlocks   // Вывести на печать все блоки
};



// Добавляем блок в список текущего автомобиля
void Auto::addBlock(std::string name)
{
    Block block;

    block.name = name;

    blocksAuto.push_back(block);
}

// Вывод на печать блоков автомобиля
void Auto::printBlocks()
{
    for(size_t i = 0; i < blocksAuto.size(); i++)
    {
        Block a = blocksAuto[i];

        std::cout << a.name << '\n';
    }
}

// Удалить блок
// Удаляется только первое совпадение
void Auto::deleteBlok(std::string yzel)
{
    for(size_t i = 0; i < blocksAuto.size(); i++)
    {
        Block a = blocksAuto[i];

        if(a.name == yzel)
        {
            blocksAuto.erase(blocksAuto.begin() + i);
            break;
        }
    }
}

// Работа с блоками автомобиля
void Auto::menu()
{
    bool temp = true;
    while(temp)
    {
        std::cout << "\n";
        std::cout << "#### MENU " << name << " ####" << "\n";
        std::cout << "[" << BackMainMenu << "]" << "Back to main menu \n"
                  << "[" << Add_Block    << "]" << "Add block \n"
                  << "[" << DeleteBlock  << "]" << "Delete block \n"
                  << "[" << SelectBlock  << "]" << "Select block \n"
                  << "[" << PrintBlocks  << "]" << "Print blocks \n";
        std::cout << "-> ";
        std::string tmp;
        std::cin >> tmp;
        int operation;
        std::cout << '\n';

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
            case BackMainMenu:
            {
                temp = false;
                break;
            }

            case Add_Block:
            {
                std::cout << "Add a block the cars \n";
                std::cout << "\n";

                std::string name;
                std::cout << "-> ";
                std::cin >> name;
                std::cout << "\n";

                addBlock(name);
                std::cout << "\n";

                break;
            }

            case DeleteBlock:
            {
                std::cout << "Enter a block to delete \n";
                std::cout << "\n";

                std::string block;
                std::cout << "-> ";
                std::cin >> block;
                std::cout << "-> ";

                deleteBlok(block);

                printBlocks();
                std::cout << "\n";

                break;
            }

            case SelectBlock:
            {
                std::cout << "Enter a block to select \n";
                std::cout << "\n";

                printBlocks();
                std::cout << "\n";

                std::string block;
                std::cout << "-> ";
                std::cin >> block;

                for(size_t i = 0; i < blocksAuto.size(); i++)
                {
                    Block& a = blocksAuto[i];

                    if(a.name == block)
                    {
                        a.menu();
                    }
                }

                break;
            }

            case PrintBlocks:
            {
                printBlocks();
                std::cout << '\n';
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

