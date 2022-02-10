#include "airplane.h"

//------------------------------------------------------------------------------
// ввод самолёта
void In(airplane &p, FILE* file) {
    fscanf(file, "%d %d %d %d", &p.speed, &p.distance, &p.fly_distance, &p.load_capacity);
}


//------------------------------------------------------------------------------
// инициализация рандомного самолёта
void InRnd(airplane &p) {
    p.speed = Random();
    p.distance = Random();
    p.fly_distance = Random();
    p.load_capacity = Random();
}


//------------------------------------------------------------------------------
// вывод самолета
void Out(airplane &p, FILE* file) {
    fprintf(
            file,
            "Plane: speed = %d, distance = %d, fly distance = %d, load capacity = %d. Optimal time = %lf.\n",
            p.speed,
            p.distance,
            p.fly_distance,
            p.load_capacity,
            OptimalTime(p)
    );
}

//------------------------------------------------------------------------------
// вычисление оптимального времени, для самолёта
// я не уверен, идеальное время дожно считаться по длинне полёта или расстоянию между пунктами
// я считаю по дистанции полета т.к. в противном весь транспорт будет иметь идентичную функцию, а это скучно
double OptimalTime(airplane &p) {
    return static_cast<double>(p.fly_distance) /  static_cast<double>(p.speed);
}