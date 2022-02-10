//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2(int size) {
    printf("incorrect numer of figures = %d. Set 0 < number <= 10000\n", size);
}

void errMessage3() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {

    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    Init(c);

    if(!strcmp(argv[1], "-f")) {
        FILE* input =  fopen(argv[2], "r");
        In(c, input);
        fclose(input);
    } else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            errMessage2(size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором рандомных чисел
        InRnd(c, size);
    } else {
        errMessage3();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE* output = fopen(argv[3], "w");
    fprintf(output, "Filled container:\n");
    Out(c, output);

    // The 2nd part of task
    FILE* output2 = fopen(argv[4], "w");
    fprintf(output2, "Sorted container:\n");
    ShakerSort(c, c.len);
    Out(c, output2);

    Clear(c);
    printf("Stop\n");

    fclose(output);
    fclose(output2);
    return 0;
}