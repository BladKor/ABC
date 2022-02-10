#include "container.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
// я не обрабатываю неправильные обьекты
void In(container &c, FILE* file) {
    while(!feof(file)) {
        if((c.cont[c.len] = In(file)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
// InRnd по идее никогда не возвращает nullptr, но это лишний нвариант, который может потом нарушиться
// так что я не стал его вводаить, в место этого, игнорирую невалидный обьект, если InRnd вернет его
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, FILE* file) {
    fprintf(file, "Container contains %d elements.\n", c.len);
    for(int i = 0; i < c.len; i++) {
        fprintf(file, "%d: ", i);
        Out(*(c.cont[i]), file);
    }
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Шейкерная сортировка. Сортирует контейнер по убыванию
void ShakerSort(container &c, int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (Average(*c.cont[i]) < Average(*c.cont[i + 1])) {
                Swap(*c.cont[i], *c.cont[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (Average(*c.cont[i]) < Average(*c.cont[i + 1])) {
                Swap(*c.cont[i], *c.cont[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}