#ifndef CARS_H
#define CARS_H

#include <string>
#include <map>

// Список известных автомобилей
// int - это ключ, std::string - это значение
std::map<int, std::string> cars =
{
    {10, "LADA"      },
    {20, "TOYOTA"    },
    {30, "SKODA"     },
    {40, "VOLKSWAGEN"},
    {80, "KIA"       }
};
#endif // CARS_H
