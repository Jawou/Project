#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include "Classes.h"

int main()
{
    Cube Test;
    Test.Color = Color3(0, 125, 125);
    Test.Size = Vector3(5, 5, 5);
    Test.Position = CFrame(125, 0, 0);

    Test.CreateRelVert();
    Test.CreateAbsTriangles();
    for (int i = 0; i < 12; i++)
    {
        printf("triangle((%f,%f,%f),(%f,%f,%f),(%f,%f,%f))\n", Test.AbsTriangles[i][0].X, Test.AbsTriangles[i][0].Y, Test.AbsTriangles[i][0].Z, Test.AbsTriangles[i][1].X, Test.AbsTriangles[i][1].Y, Test.AbsTriangles[i][1].Z, Test.AbsTriangles[i][2].X, Test.AbsTriangles[i][2].Y, Test.AbsTriangles[i][2].Z);
    }


    printf("\n%f", Test.Size.X);
    return 0;
}
