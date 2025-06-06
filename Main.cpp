#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include "Classes.h"
#include "Functions.h"


void DisplayCube(Cube Test) {
    Test.CreateRelVert();
    Test.CreateAbsTriangles();
    for (int i = 0; i < 12; i++)
    {
        printf("triangle((%f,%f,%f),(%f,%f,%f),(%f,%f,%f))\n", Test.AbsTriangles[i][0].X, Test.AbsTriangles[i][0].Y, Test.AbsTriangles[i][0].Z, Test.AbsTriangles[i][1].X, Test.AbsTriangles[i][1].Y, Test.AbsTriangles[i][1].Z, Test.AbsTriangles[i][2].X, Test.AbsTriangles[i][2].Y, Test.AbsTriangles[i][2].Z);
    }
}

void DisplayMatrix(Cube Test) {
    for (int i = 0; i < 3; i++)
    {
        printf("%f,%f,%f\n", Test.Position.RotationMatrix[i][0], Test.Position.RotationMatrix[i][1], Test.Position.RotationMatrix[i][2]);
    }
}   

int main()
{
    Cube Test;
    Test.Color = Color3(0, 0, 0);
    Test.Size = Vector3(100000, 100000, 100000);
    Test.Position = CFrame(0, 0, 0);
    Test.Position.Alpha = 125;
    Test.Position.Beta = 12;
    Test.Position.UpdateMatrix();


    DisplayCube(Test);

    return 0;
}
