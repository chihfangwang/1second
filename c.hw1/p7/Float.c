#include "Float.h"
void decompose(double num, int *i_part, double *f_part) {
    *i_part = (int)num;
    *f_part = num - *i_part;
}
