#pragma once

#include<math.h>
#include <stdio.h>
#include"Classes.h"
#include"Functions.h"
//Outputs the cube for desmos to render
void DesmosDisplay(Object& Test) {
    Test.CreateRelVert();
    Test.CreateAbsTriangles();
    for (int i = 0; i < Test.NumberOfTriangles; i++)
    {
        printf("triangle((%f,%f,%f),(%f,%f,%f),(%f,%f,%f))\n", Test.AbsTriangles[i][0].X, Test.AbsTriangles[i][0].Y, Test.AbsTriangles[i][0].Z, Test.AbsTriangles[i][1].X, Test.AbsTriangles[i][1].Y, Test.AbsTriangles[i][1].Z, Test.AbsTriangles[i][2].X, Test.AbsTriangles[i][2].Y, Test.AbsTriangles[i][2].Z);
    }
}

//Outputs the matrix of a cube for debug testing
void DisplayMatrix(Cube Test) {
    for (int i = 0; i < 3; i++) {
        printf("%f,%f,%f\n", Test.Position.RotationMatrix[i][0], Test.Position.RotationMatrix[i][1], Test.Position.RotationMatrix[i][2]);
    }
}