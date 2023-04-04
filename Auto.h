#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <vector>

#include "Block.h"
#include "Part.h"
#include "Auto.h"


// Структура автомобиля
struct Auto
{
    int id;
    std::string name;

    std::vector<Block> blocksAuto;

    void menu();

    void addBlock(std::string name);

    void deleteBlok(std::string yzel);

    void printBlocks();
};



#endif // AUTO_H
