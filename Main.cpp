#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include "Classes.h"


void DisplayCube(Cube Test) {
    Test.CreateRelVert();
    Test.CreateAbsTriangles();
    for (int i = 0; i < 12; i++)
    {
        printf("triangle((%f,%f,%f),(%f,%f,%f),(%f,%f,%f))\n", Test.AbsTriangles[i][0].X, Test.AbsTriangles[i][0].Y, Test.AbsTriangles[i][0].Z, Test.AbsTriangles[i][1].X, Test.AbsTriangles[i][1].Y, Test.AbsTriangles[i][1].Z, Test.AbsTriangles[i][2].X, Test.AbsTriangles[i][2].Y, Test.AbsTriangles[i][2].Z);
    }
}

int main()
{
    Cube Floor;
    Floor.Color = Color3(0, 0, 0);
    Floor.Size = Vector3(40, 40, 1);
    Floor.Position = CFrame(0, 0, 0);

    Cube Trunk;
    Trunk.Color = Color3(0, 0, 0);
    Trunk.Size = Vector3(4, 4, 20);
    Trunk.Position = CFrame(0, 0, 10);

    Cube Leaves;
    Leaves.Color = Color3(0, 0, 0);
    Leaves.Size = Vector3(10, 10, 10);
    Leaves.Position = CFrame(0, 0, 25);

    Leaves.Position.AddPos(Vector3(150, 1, 1));
    DisplayCube(Floor);
    DisplayCube(Trunk);
    DisplayCube(Leaves);
    return 0;
}
