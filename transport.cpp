#include "transport.h"


//------------------------------------------------------------------------------
// ввод транспорта
// если введены неправильные данные - возвращает nullptr,который считается невалидным оБьектом
transport* In(FILE* file) {
    transport *t = new transport;
    char kind[9];
    fscanf(file, "%s", kind);
    if (strcmp(kind, "airplane") == 0) {
        t->k = transport::AIRPLANE;
        In(t->p, file);
    } else if (strcmp(kind, "train") == 0) {
        t->k = transport::TRAIN;
        In(t->t, file);
    } else if (strcmp(kind, "ship") == 0) {
        t->k = transport::SHIP;
        In(t->s, file);
        // обработка неправильно введенных данных
        if (t->s.ship_kind == ship::ERROR) {
            delete t;
            return nullptr;
        }
    } else {
        delete t;
        return nullptr;
    }
    return t;
}

//------------------------------------------------------------------------------
// инициализация рандомного транспорта
transport *InRnd() {
    transport *t = new transport;
    auto k = Random();

    if (k % 3 == 0) {
        t->k = transport::AIRPLANE;
        InRnd(t->p);
    } else if (k % 3 == 1) {
        t->k = transport::TRAIN;
        InRnd(t->t);
    } else {
        t->k = transport::SHIP;
        InRnd(t->s);
    }

    return t;
}


//------------------------------------------------------------------------------
// вывод транспорта
void Out(transport &t, FILE* file) {
    if (t.k == transport::AIRPLANE) {
        Out(t.p, file);
    } else if (t.k == transport::TRAIN) {
        Out(t.t, file);
    } else  {
        Out(t.s, file);
    }
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для транспорта
double OptimalTime(transport &t) {
    if (t.k == transport::AIRPLANE) {
        return OptimalTime(t.p);
    } else if (t.k == transport::TRAIN) {
        return OptimalTime(t.t);
    } else {
        return OptimalTime(t.s);
    }
}

//------------------------------------------------------------------------------
// смена двух значений местами
void Swap(transport &t1, transport &t2) {
    transport temp;
    temp = t1;
    t1 = t2;
    t2 = temp;
}

//------------------------------------------------------------------------------
// вспомогательная функция для сортировки
double Average(transport &t) {
    switch (t.k) {
        case transport::AIRPLANE:
            return OptimalTime(t.p);
        case transport::TRAIN:
            return OptimalTime(t.t);
        case transport::SHIP:
            return OptimalTime(t.s);
        default:
            return 0.0;
    }
}