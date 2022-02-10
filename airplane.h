#ifndef __airplane__
#define __airplane__

#include <fstream>

#include "rnd.h"

struct airplane {
    int speed, distance;
    int fly_distance, load_capacity;
};


//------------------------------------------------------------------------------
// ввод самолёта
void In(airplane &p, FILE* file);


//------------------------------------------------------------------------------
// инициализация рандомного самолёта
void InRnd(airplane &p);


//------------------------------------------------------------------------------
// вывод самолета
void Out(airplane &p, FILE* file);


//------------------------------------------------------------------------------
// вычисление оптимального времени, для самолёта
double OptimalTime(airplane &p);

#endif //__airplane__
