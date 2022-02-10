#include "ship.h"

//------------------------------------------------------------------------------
// ввод корабля
void In(ship &s, FILE* file) {
    char kind[9];
    fscanf(file, "%d %d %d %s", &s.speed, &s.distance, &s.displacement, kind);

    if (strcmp(kind, "liner") == 0) {
        s.ship_kind = ship::LINER;
    } else if (strcmp(kind, "tug") == 0) {
        s.ship_kind = ship::TUG;
    } else if (strcmp(kind, "tanker") == 0) {
        s.ship_kind = ship::TANKER;
    } else {
        s.ship_kind = ship::ERROR;
    }
}


//------------------------------------------------------------------------------
// инициализация рандомного корабля
void InRnd(ship &s) {
    s.speed = Random();
    s.distance = Random();
    s.displacement = Random();

    int kind = Random();
    if (kind % 3 == 0) {
        s.ship_kind = ship::LINER;
    } else if (kind % 3 == 1) {
        s.ship_kind = ship::TUG;
    } else {
        s.ship_kind = ship::TANKER;
    }
}


//------------------------------------------------------------------------------
// вывод корабля
void Out(ship &s, FILE* file) {
    fprintf(
            file,
            "Ship: speed = %d, distance = %d, displacement = %d, ",
            s.speed,
            s.distance,
            s.displacement
    );


    if (s.ship_kind == ship::LINER) {
        fprintf(file, "ship kind = liner. ");
    } else if (s.ship_kind == ship::TUG) {
        fprintf(file, "ship kind = tug. ");
    } else if (s.ship_kind == ship::TANKER) {
        fprintf(file, "ship kind = tanker. ");
    }

    fprintf(file, "Optimal time = %lf.\n", OptimalTime(s));
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для корабля
double OptimalTime(ship &s) {
    return static_cast<double>(s.distance) /  static_cast<double>(s.speed);
}