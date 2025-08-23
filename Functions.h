#pragma once

#include<math.h>
#include <stdio.h>

void MultMatrix(float(&Small)[3], float Big[3][3]) {
    float temp[3] = { Small[0], Small[1], Small[2] };

    Small[0] = temp[0] * Big[0][0] + temp[1] * Big[1][0] + temp[2] * Big[2][0];
    Small[1] = temp[0] * Big[0][1] + temp[1] * Big[1][1] + temp[2] * Big[2][1];
    Small[2] = temp[0] * Big[0][2] + temp[1] * Big[1][2] + temp[2] * Big[2][2];
}

//Turnes degree to radian
float DegreeToRadian(float Degree) {
    float pi = 2 * acos(0.0);
    return Degree * pi / 180;
}

//Turns a string into an int for a hastable
int StringToInt(char Name[99]) {
    printf("%d", Name[51]);
    return 0;
};
