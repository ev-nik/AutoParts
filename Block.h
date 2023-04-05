#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

#include "Part.h"

struct Block
{
    std::string name;
    std::vector<Part> blockParts;

    void addPart(std::string name);
    void printParts();
    void menu();
    void deletePart(std::string namePart);
};
#endif // BLOCK_H
