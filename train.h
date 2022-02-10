#ifndef __train__
#define __train__

#include <fstream>

#include "rnd.h"

struct train {
    int speed, distance;
    int carriage_counter;
};

//------------------------------------------------------------------------------
// ввод поезда
void In(train &t, FILE* file);

//------------------------------------------------------------------------------
// инициализация рандомного поезда
void InRnd(train &t);

//------------------------------------------------------------------------------
// вывод поезда
void Out(train &t, FILE* file);

//------------------------------------------------------------------------------
// вычисление оптимального времени, для поезда
double OptimalTime(train &t);

#endif //__train__