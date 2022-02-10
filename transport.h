#ifndef __transport__
#define __transport__

#include "airplane.h"
#include "train.h"
#include "ship.h"
#include "rnd.h"

struct transport {
    enum key {AIRPLANE, TRAIN, SHIP};
    key k;
    union {
        airplane p;
        train t;
        ship s;
    };
};


//------------------------------------------------------------------------------
// ввод транспорта из потока ввода
transport *In(FILE* file);


//------------------------------------------------------------------------------
// инициализация рандомного транспорта
transport *InRnd();

//------------------------------------------------------------------------------
// вывод транспорта в поток вывода
void Out(transport& t, FILE* file);


//------------------------------------------------------------------------------
// вычисление оптимального времени в пути, для транспорта
double OptimalTime(transport &t);

// функция обмена значениями
void Swap(transport &t1, transport &t2);

// вспомогательная функция дл сортировки
double Average(transport &t);

#endif