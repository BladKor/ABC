#ifndef __ship__
#define __ship__

#include <cstring>
#include <cstdio>

#include "rnd.h"

struct ship {
    int speed, distance;
    int displacement;
    enum vessel_type {LINER, TUG, TANKER, ERROR};
    vessel_type ship_kind;
};


//------------------------------------------------------------------------------
// ввод корабля
void In(ship &s, FILE* file);

//------------------------------------------------------------------------------
// инициализация рандомного корабля
void InRnd(ship &s);

//------------------------------------------------------------------------------
// вывод корабля
void Out(ship &s, FILE* file);

//------------------------------------------------------------------------------
// вычисление оптимального времени, для корабля
double OptimalTime(ship &s);

#endif //__ship__