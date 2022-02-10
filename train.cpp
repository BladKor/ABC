#include "train.h"


//------------------------------------------------------------------------------
// ввод поезда
void In(train &t, FILE* file) {
    fscanf(file, "%d %d %d %d", &t.speed, &t.distance, &t.carriage_counter);
}

//------------------------------------------------------------------------------
// инициализация рандомного поезда
void InRnd(train &t) {
    t.speed = Random();
    t.distance = Random();
    t.carriage_counter = Random();
}

//------------------------------------------------------------------------------
// вывод поезда
void Out(train &t, FILE* file) {
    fprintf(
            file,
            "Train: speed = %d, distance = %d, carriage counter = %d. ",
            t.speed,
            t.distance,
            t.carriage_counter
    );

    fprintf(file, "Optimal time = %lf.\n", OptimalTime(t));
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для поезда
double OptimalTime(train &t) {
    return static_cast<double>(t.distance) /  static_cast<double>(t.speed);
}