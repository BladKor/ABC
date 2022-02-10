#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "transport.h"
#include <algorithm>

struct container {
    enum {max_len = 10000};
    int len;
    transport *cont[max_len];
};

// Инициализирует пустой контейнер
void Init(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, FILE* file);

// Рандомный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, FILE* file);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Шейкерная сортировка элементов контейнера по времени идеального пути
void ShakerSort(container &c, int size);

#endif
