#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// генерация рандомного числа от 1 до 100
//------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 100 + 1;
}

#endif //__rnd__