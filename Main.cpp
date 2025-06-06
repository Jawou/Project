#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>


#include "Classes.h"
#include "Functions.h"
#include "Debug.h"

int main()
{
    Cube Test;
    Test.Color = Color3(0, 0, 0);
    Test.Size = Vector3(10, 30, 10);
    Test.Position = CFrame(0, 10, 0);
    Test.Position.Alpha = 0.785398;
    Test.Position.Beta = 0.785398;
    Test.Position.Gamma = 0.785398;
    Test.Position.UpdateMatrix();
    DisplayCube(Test);

    Cube Test2;
    Test2.Color = Color3(0, 0, 0);
    Test2.Size = Vector3(10, 10, 10);
    Test2.Position = CFrame(0, 0, 0);
    Test2.Position.Alpha = 0;
    Test2.Position.Beta = 0;
    Test2.Position.UpdateMatrix();
    DisplayCube(Test2);

    return 0;
}
