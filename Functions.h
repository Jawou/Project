#pragma once

#include<math.h>
#include <stdio.h>

void MultMatrix(double(&Small)[3], double Big[3][3]) {
    double temp[3] = { Small[0], Small[1], Small[2] };

    Small[0] = temp[0] * Big[0][0] + temp[1] * Big[1][0] + temp[2] * Big[2][0];
    Small[1] = temp[0] * Big[0][1] + temp[1] * Big[1][1] + temp[2] * Big[2][1];
    Small[2] = temp[0] * Big[0][2] + temp[1] * Big[1][2] + temp[2] * Big[2][2];
}

double DegreeToRadian(double Degree) {
    double pi = 2 * acos(0.0);
    return Degree * pi / 180;
}
